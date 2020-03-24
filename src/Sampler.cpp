#include "Sampler.h"
#include <algorithm>
// ------------------------------------------------------------------ default constructor

Sampler::Sampler() : num_samples(1),num_sets(83),counts(0),jump(0) {
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

// ------------------------------------------------------------------ constructor

Sampler::Sampler(const int ns) : num_samples(ns),num_sets(83),counts(0),jump(0) {
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

// ------------------------------------------------------------------ constructor

Sampler::Sampler(const int ns, const int n_sets) : num_samples(ns),num_sets(n_sets),counts(0),jump(0) {
	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

// ------------------------------------------------------------------ copy constructor

Sampler::Sampler(const Sampler& s) : num_samples(s.num_samples),num_sets(s.num_sets),samples(s.samples),
                                     shuffled_indices(s.shuffled_indices),disk_samples(s.disk_samples),hemisphere_samples(s.hemisphere_samples),
                                    //sphere_samples(s.sphere_samples),
                                    counts(s.counts),jump(s.jump) {}

// ------------------------------------------------------------------ assignment operator

Sampler& Sampler::operator= (const Sampler& rhs) {
	if (this == &rhs)
		return (*this);

	num_samples 		= rhs.num_samples;
	num_sets			= rhs.num_sets;
	samples				= rhs.samples;
	shuffled_indices	= rhs.shuffled_indices;
	disk_samples		= rhs.disk_samples;
	hemisphere_samples	= rhs.hemisphere_samples;
	// sphere_samples		= rhs.sphere_samples;
	counts				= rhs.counts;
	jump				= rhs.jump;

	return (*this);
}

Sampler::~Sampler(void) {}

// ------------------------------------------------------------------- set_num_sets

void Sampler::set_num_sets(const int np) { num_sets = np; }

// ------------------------------------------------------------------- shuffle_x_coordinates
// shuffle the x coordinates of the points within each set

void Sampler::shuffle_x_coordinates() {
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i <  num_samples - 1; i++) {
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].x;
			samples[i + p * num_samples + 1].x = samples[target].x;
			samples[target].x = temp;
		}
}

// ------------------------------------------------------------------- shuffle_y_coordinates
// shuffle the y coordinates of the points within set

void Sampler::shuffle_y_coordinates() {
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i <  num_samples - 1; i++) {
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].y;
			samples[i + p * num_samples + 1].y = samples[target].y;
			samples[target].y = temp;
		}
}

// ------------------------------------------------------------------- map_samples_to_disk

void Sampler::map_samples_to_disk() {
    int sizes = samples.size();
    float r,phi;    // polar coordinates
    Point2D sp;     // sample point on unit disk

    disk_samples.reserve(sizes);

    for(int j = 0;j < sizes;j++) {
        // map sample point to [-1,1] [-1,1]
        sp.x = 2.0*samples[j].x - 1.0;
        sp.y = 2.0*samples[j].y - 1.0;

        if(sp.x > -sp.y) {                  // sectors 1 and 2
            if(sp.x > sp.y) {               // sector 1
                r = sp.x;
                phi = sp.y/sp.x;
            }
            else {
                r = sp.y;
                phi = 2-sp.x/sp.y;          // sector 2
            }
        }
        else {                              // sectors 3 and 4
            if(sp.x < sp.y) {               // sector 3
                r = -sp.x;
                phi = 4+sp.y/sp.x;
            }
            else {                          // sector 4
                r = -sp.y;
                if(sp.y != 0)               // avoid division by zero at origin
                    phi = 6 - sp.x/sp.y;
                else
                    phi = 0.0;
            }
        }

        phi *= PI/4.0;
        disk_samples[j].x = r*cos(phi);
        disk_samples[j].y = r*sin(phi);
    }
    samples.erase(samples.begin(),samples.end());
}

// ------------------------------------------------------------------- map_sample_to_hemisphere

// Maps the 2D sample points to 3D points on a unit hemisphere with a cosine power
// density distribution in the polar angle
void Sampler::map_samples_to_hemisphere(const float e) {
    int sizes = samples.size();
    hemisphere_samples.reserve(num_samples * num_sets);

    for(int j = 0;j < sizes;j++) {
        float cos_phi = cos(2.0*PI*samples[j].x);
        float sin_phi = sin(2.0*PI*samples[j].x);
        float cos_theta = pow(1.0-samples[j].y,1.0/(e+1.0));
        float sin_theta = sqrt(1.0-cos_theta*cos_theta);
        float pu = sin_theta*cos_phi;
        float pv = sin_theta*sin_phi;
        float pw = cos_theta;

        hemisphere_samples.push_back(Point3D(pu,pv,pw));
    }
}
// ------------------------------------------------------------------- setup_shuffled_index
// sets up randomly shuffled index for the samples array

void Sampler::setup_shuffled_indices() {
	shuffled_indices.reserve(num_samples * num_sets);
	vector<int> indices;

	for (int j = 0; j < num_samples; j++)
		indices.push_back(j);

	for (int p = 0; p < num_sets; p++) {
		random_shuffle(indices.begin(), indices.end());

		for (int j = 0; j < num_samples; j++)
			shuffled_indices.push_back(indices[j]);
	}
}

// ------------------------------------------------------------------- sample_unit_square

Point2D Sampler::sample_unit_square() {
    if(counts%num_samples == 0) // start of a new pixel
        jump = (rand_int()%num_sets) * num_samples;
    return samples[jump + shuffled_indices[jump + counts++ % num_samples]];
}

// ------------------------------------------------------------------- sample_unit_disk

Point2D Sampler::sample_unit_disk(void) {
	if (counts % num_samples == 0)  									// start of a new pixel
		jump = (rand_int() % num_sets) * num_samples;

	return (disk_samples[jump + shuffled_indices[jump + counts++ % num_samples]]);
}

// ------------------------------------------------------------------- sample_hemisphere

Point3D Sampler::sample_hemisphere() {
	if (counts % num_samples == 0)  									// start of a new pixel
		jump = (rand_int() % num_sets) * num_samples;

	return (hemisphere_samples[jump + shuffled_indices[jump + counts++ % num_samples]]);
}

