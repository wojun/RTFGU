#ifndef JITTERED_H
#define JITTERED_H

#include "Sampler.h"


class Jittered : public Sampler
{
    public:
        Jittered();
		Jittered(const int num_samples);
		Jittered(const int num_samples, const int m);
		Jittered(const Jittered &u);
		Jittered& operator= (const Jittered &rhs);
        virtual Jittered* clone() const override;
        virtual ~Jittered();

    private:
        void generate_samples() override;
};

#endif // JITTERED_H
