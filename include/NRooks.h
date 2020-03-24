#ifndef NROOKS_H
#define NROOKS_H

#include "Sampler.h"


class NRooks : public Sampler
{
    public:
        NRooks();
        NRooks(const int num_samples);
		NRooks(const int num_samples, const int m);
		NRooks(const NRooks& nr);
		NRooks& operator= (const NRooks& rhs);
		virtual NRooks*	clone(void) const;
        virtual ~NRooks();

    private:
        virtual void generate_samples() override;
};

#endif // NROOKS_H
