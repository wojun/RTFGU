#ifndef REGULAR_H
#define REGULAR_H

#include "Sampler.h"


class Regular : public Sampler
{
    public:
        Regular();
		Regular(const int num);
		Regular(const Regular &u);
		Regular& operator= (const Regular &rhs);
		virtual Regular* clone() const override;
		virtual ~Regular();
		virtual void generate_samples() override;
};

#endif // REGULAR_H
