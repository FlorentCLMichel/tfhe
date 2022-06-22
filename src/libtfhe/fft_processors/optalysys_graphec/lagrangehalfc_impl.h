#ifndef LAGRANGEHALFC_IMPL_H
#define LAGRANGEHALFC_IMPL_H

#include <cassert>
#include "simulators.h"
constexpr unsigned int ACCURACY = 40;
#include <complex>
typedef std::complex<double> cplx;
#include "tfhe.h"
#include "polynomials.h"


class FFT_Processor_graphec {
    public:
    const int32_t _2N;
    const int32_t N;    
    const int32_t Ns2;

    private:
    unsigned int index_simulator;
    cplx* in;
    cplx* out;

    public:
    cplx* omegaxminus1;

    FFT_Processor_graphec(const int32_t N);
    void execute_reverse_int(cplx* res, const int32_t* a);
    void execute_reverse_torus32(cplx* res, const Torus32* a);
    void execute_direct_Torus32(Torus32* res, const cplx* a);
    ~FFT_Processor_graphec();
};

extern thread_local FFT_Processor_graphec fp1024_graphec;

/**
 * structure that represents a real polynomial P mod X^N+1
 * as the N/2 complex numbers:
 * P(w), P(w^3), ..., P(w^(N-1))
 * where w is exp(i.pi/N)
 */
struct LagrangeHalfCPolynomial_IMPL
{
   cplx* coefsC;
   FFT_Processor_graphec* proc;

   LagrangeHalfCPolynomial_IMPL(int32_t N);
   ~LagrangeHalfCPolynomial_IMPL();
};

#endif // LAGRANGEHALFC_IMPL_H
