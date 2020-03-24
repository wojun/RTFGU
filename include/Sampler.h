#ifndef SAMPLER_H
#define SAMPLER_H

#include "Point2D.h"
#include "Point3D.h"
#include "Maths.h"
#include <vector>

using namespace std;


class Sampler
{
    public:
        Sampler();
        Sampler(const int num);
		Sampler(const int num, const int num_sets);
		Sampler(const Sampler& s);
		Sampler& operator= (const Sampler& rhs);
		virtual Sampler* clone(void) const = 0;
        virtual ~Sampler();

		virtual void generate_samples() = 0; // generate sample patterns in a unit square
		void set_num_sets(const int np);
		void shuffle_x_coordinates();
		void shuffle_y_coordinates();
		void setup_shuffled_indices();       // set up the randomly shuffled index
		void map_samples_to_disk();
		void map_samples_to_hemisphere(const float e);
		void shuffled_samples();             // randomly shuffle the samples in each pattern
		Point2D sample_unit_square();        // get next sample on unit square
		Point2D sample_unit_disk();          // get next sample on this disk
		Point3D	sample_hemisphere();         // get next sample on unit hemisphere

		int get_num_samples();

    protected:
        int 					num_samples;     		// the number of sample points in a set
		int 					num_sets;				// the number of sample sets
		vector<Point2D>			samples;				// sample points on a unit square
		vector<int>				shuffled_indices;		// shuffled samples array indices
		vector<Point2D>			disk_samples;			// sample points on a unit disk
		vector<Point3D> 		hemisphere_samples;		// sample points on a unit hemisphere
		// vector<Point3D> 		sphere_samples;			// sample points on a unit sphere
		unsigned long 			counts;					// the current number of sample points used
		int 					jump;					// random index jump

};

inline Sampler::get_num_samples() { return num_samples; }
#endif // SAMPLER_H
