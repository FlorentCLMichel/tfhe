/*
 * This file is designed to test the Fourier transform functions. 
 * It is a bit buggy—in particular, the second and third types do not play 
 * well with each other.
 */

#include <iostream>
#include <complex>
typedef std::complex<double> cplx;
#include "tfhe.h"

constexpr unsigned int FT_SIZE = 1024;
constexpr unsigned int N_COEFFS = 10;

int main () {
    
    // // first type of Fourier transform
    // IntPolynomial *input_1 = new_IntPolynomial_array(1, FT_SIZE);
    // for (unsigned int j = 0; j < FT_SIZE; j++) {
    //     input_1->coefs[j] = j;
    // }
    // LagrangeHalfCPolynomial *output_1 = new_LagrangeHalfCPolynomial(FT_SIZE);
    // IntPolynomial_ifft(output_1, input_1);
    // cplx* coefs_1 = (cplx*) output_1->data;
    // for (unsigned int i=0; i<N_COEFFS; i++) {
    //     std::cout << coefs_1[i].real()
    //               << ", "
    //               << coefs_1[i].imag()
    //               << "\t";
    // }
    // std::cout << std::endl;
    // for (unsigned int i=FT_SIZE/2; i<FT_SIZE/2+N_COEFFS; i++) {
    //     std::cout << coefs_1[i].real()
    //               << ", "
    //               << coefs_1[i].imag()
    //               << "\t";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // 
    // free(input_1);
    // free(output_1);


    // // // second type of Fourier transform
    // TorusPolynomial input_2(FT_SIZE);
    // for (unsigned int j = 0; j < FT_SIZE; j++) {
    //     input_2.coefsT[j] = j;
    // }
    // LagrangeHalfCPolynomial *output_2 = new_LagrangeHalfCPolynomial(FT_SIZE);
    // TorusPolynomial_ifft(output_2, &input_2);
    // cplx* coefs_2 = (cplx*) output_2->data;
    // for (unsigned int i=0; i<N_COEFFS; i++) {
    //     std::cout << coefs_2[i].real()
    //               << ", "
    //               << coefs_2[i].imag()
    //               << "\t";
    // }
    // std::cout << std::endl;
    // for (unsigned int i=FT_SIZE/2; i<FT_SIZE/2+N_COEFFS; i++) {
    //     std::cout << coefs_2[i].real()
    //               << ", "
    //               << coefs_2[i].imag()
    //               << "\t";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // 
    // delete_TorusPolynomial_array(1, &input_2);


    // third type of Fourier transforms
    LagrangeHalfCPolynomial *input_3 = new_LagrangeHalfCPolynomial(FT_SIZE);
    cplx* coefs_3 = (cplx*) input_3->data;
    for (unsigned int j = 0; j < FT_SIZE; j++) {
        coefs_3[j] = j;
    }
    TorusPolynomial output_3(FT_SIZE);
    TorusPolynomial_fft(&output_3, input_3);
    for (unsigned int i=0; i<N_COEFFS; i++) {
        std::cout << output_3.coefsT[i]
                  << "\t";
    }
    std::cout << std::endl;
    for (unsigned int i=FT_SIZE/2; i<FT_SIZE/2+N_COEFFS; i++) {
        std::cout << output_3.coefsT[i]
                  << "\t";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    free(input_3);

    return 0;
}
