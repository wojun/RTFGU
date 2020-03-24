#include "NRooks.h"

// ---------------------------------------------------------------- default constructor

NRooks::NRooks() : Sampler() {}

// ---------------------------------------------------------------- constructor

NRooks::NRooks(const int num_samples): Sampler(num_samples) {
	generate_samples();
}

// ---------------------------------------------------------------- constructor

NRooks::NRooks(const int num_samples, const int m) : Sampler(num_samples, m) {
	generate_samples();
}

// ---------------------------------------------------------------- copy constructor

NRooks::NRooks(const NRooks& nr) : Sampler(nr) { generate_samples(); }

// ---------------------------------------------------------------- assignment operator

NRooks& NRooks::operator= (const NRooks& rhs) {
	if (this == &rhs)
		return (*this);

	Sampler::operator=(rhs);

	return (*this);
}

// ---------------------------------------------------------------- clone

NRooks*	NRooks::clone() const { return (new NRooks(*this));}

// ---------------------------------------------------------------- destructor

NRooks::~NRooks() {}


// ---------------------------------------------------------------- generate_samples

void NRooks::generate_samples() {
	// generate samples along main diagonal
	for (int p = 0; p < num_sets; p++)
		for (int j = 0; j < num_samples; j++) {
			Point2D sp((j + rand_float()) / num_samples, (j + rand_float()) / num_samples);
			samples.push_back(sp);
		}
    // shuffling the sample points
	shuffle_x_coordinates();
	shuffle_y_coordinates();
}
