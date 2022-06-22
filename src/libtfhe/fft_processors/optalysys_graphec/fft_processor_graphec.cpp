#include "lagrangehalfc_impl.h"

FFT_Processor_graphec::FFT_Processor_graphec(const int32_t N): _2N(2*N), N(N), Ns2(N/2) {
    omegaxminus1 = new cplx[_2N];
    in = new cplx[_2N];
    out = new cplx[_2N];
    index_simulator = define(ACCURACY, _2N);
    for (int32_t x=0; x<_2N; x++) {
	    omegaxminus1[x]=cplx(cos(x*M_PI/N)-1., sin(x*M_PI/N)); 
    }
}

void FFT_Processor_graphec::execute_reverse_int(cplx* res, const int* a) {
    for (int32_t i=0; i<N; i++) in[i]=a[i]/2.;
    for (int32_t i=0; i<N; i++) in[N+i]=-in[i];
    ift_inplace_stable_ns(index_simulator, (double*) in, (double*) out);
    for (int32_t i=0; i<Ns2; i++) res[i]=out[2*i+1];
    for (int32_t i=0; i<=Ns2; i++) assert(abs(out[2*i])<1e-20);
}

void FFT_Processor_graphec::execute_reverse_torus32(cplx* res, const Torus32* a) {
    static const double _2pm33 = 1./double(INT64_C(1)<<33);
    int32_t* aa = (int32_t*) a;
    for (int32_t i=0; i<N; i++) in[i]=aa[i]*_2pm33;
    for (int32_t i=0; i<N; i++) in[N+i]=-in[i];
    ift_inplace_stable_ns(index_simulator, (double*) in, (double*) out);
    for (int32_t i=0; i<Ns2; i++) res[i]=out[2*i+1];
    for (int32_t i=0; i<=Ns2; i++) assert(abs(out[2*i])<1e-20);
}

void FFT_Processor_graphec::execute_direct_Torus32(Torus32* res, const cplx* a) {
    static const double _2p33 = double(INT64_C(1)<<33);
    static const double _1sN = double(1)/double(N);
    for (int32_t i=0; i<_2N; i++) in[i]=0;
    for (int32_t i=0; i<Ns2; i++) in[2*i+1]=a[i];
    ft_inplace_stable(index_simulator, (double*) in, (double*) out);
    for (int32_t i=0; i<N; i++) res[i]=Torus32(int64_t(out[i].real()*_1sN*_2p33));
    for (int32_t i=0; i<N; i++) assert(fabs(out[N+i]+out[i])<1e-20);
}

FFT_Processor_graphec::~FFT_Processor_graphec() {
    delete[] omegaxminus1;
    delete[] in;
    delete[] out;
}


/**
 * FFT functions 
 */
EXPORT void IntPolynomial_ifft(LagrangeHalfCPolynomial* result, const IntPolynomial* p) {
    fp1024_graphec.execute_reverse_int(((LagrangeHalfCPolynomial_IMPL*)result)->coefsC, p->coefs);
}
EXPORT void TorusPolynomial_ifft(LagrangeHalfCPolynomial* result, const TorusPolynomial* p) {
    fp1024_graphec.execute_reverse_torus32(((LagrangeHalfCPolynomial_IMPL*)result)->coefsC, p->coefsT);
}
EXPORT void TorusPolynomial_fft(TorusPolynomial* result, const LagrangeHalfCPolynomial* p) {
    fp1024_graphec.execute_direct_Torus32(result->coefsT, ((LagrangeHalfCPolynomial_IMPL*)p)->coefsC);
}
