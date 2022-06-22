//_____________________________________________________________________________
//
// C++ interface for the default simulators
//
// Must be compiled on a system where the double type matches the Real type of 
// the FFT crate.
//
// Complex numbers are represented by doublets of 64-bits floating-point 
// numbers, with the real part followed by the imaginary part.
//
// The first argument of all functions that take at least one is the index of 
// the simulator.
//_____________________________________________________________________________

#ifndef SIMULATORS_
#define SIMULATORS_

#ifndef __STDC_IEC_559__
#error "Requires IEEE 754 floating point!"
#endif

#ifdef __cplusplus
#define EXT extern "C"
#else
#define EXT extern
#include <stdbool.h>
#endif

// print basic infos about the library
EXT void print_infos();

// numbers of simulators which are defined
EXT unsigned int n_simulators();

// try to define a new simulator; return the simulator index if successful or 0 if not
//
// Arguments: 
//  * target accuracy (in number of bits)
//  * ft size
EXT unsigned int define(unsigned int, unsigned long);

// get the number of device frames used so far on the simulator
EXT unsigned long get_n_frames(unsigned int);

// get the runtime on a simulator (in s)
EXT double get_runtime_s(unsigned int);

// get the energy cost on a simulator (in J)
EXT double get_energy_cost_j(unsigned int);
 
// get the target accuracy of a simulator (in number of bits)
EXT unsigned int get_accuracy(unsigned int);

// set the target accuracy of a simulator (in number of bits)
EXT void set_accuracy(unsigned int, unsigned int);

// get the ft size for a simulator
EXT unsigned long get_ft_size(unsigned int);

// attempt to perform an out-of-place Fourier transform
//
// The second argument must be of size `2*ft_size`
EXT double* ft(unsigned int, const double*);

// attempt to perform an out-of-place inverse Fourier transform
//
// The second argument must be of size `2*ft_size`
EXT double* ift(unsigned int, const double*);

// attempt to perform an out-of-place inverse Fourier transform without scaling 
//
// The second argument must be of size `2*ft_size`
EXT double* ift_ns(unsigned int, const double*);

// attempt to perform an inplace Fourier transform and return `true` if 
// successful or `false` if an error is produced on the Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//
// The second and third arguments must be of size `2*ft_size`
EXT bool ft_inplace_stable(unsigned int, const double*, double*);

// attempt to perform an inplace inverse Fourier transform and return `true` if 
// successful or `false` if an error is produced on the Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//
// The second and third arguments must be of size `2*ft_size`
EXT bool ift_inplace_stable(unsigned int, const double*, double*);

// attempt to perform an inplace inverse Fourier transform without rescaling 
// and return `true` if successful or `false` if an error is produced on the 
// Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//
// The second and third arguments must be of size `2*ft_size`
EXT bool ift_inplace_stable_ns(unsigned int, const double*, double*);

// attempt to perform a periodic convolution
//
// Arguments: 
//  * index of the simulator
//  * left input array
//  * right input array
//
// Each argument must be of size `2*ft_size`
EXT double* convolution(unsigned int, const double*, const double*);

// attempt to perform an antiperiodic convolution
//
// Arguments: 
//  * index of the simulator
//  * left input array
//  * right input array
//
// Each argument must be of size `2*ft_size`
EXT double* polymult(unsigned int, const double*, const double*);

// attempt to perform batched inplace Fourier transforms 
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * number of Fourier transforms
EXT double* batched_ft(unsigned int, const double*, unsigned long);

// attempt to perform batched inplace Fourier transforms and return `true` if 
// successful or `false` if an error is produced on the Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//  * number of Fourier transforms
//
// The second and third arguments must be of size `2*ft_size*n_ft`, where 
// `n_ft` is the third argument
EXT bool batched_ft_inplace_stable(unsigned int, const double*, double*, unsigned long);

// attempt to perform batched inverse Fourier transforms
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * number of Fourier transforms
EXT double* batched_ift(unsigned int, const double*, unsigned long);

// attempt to perform batched inplace inverse Fourier transforms with the 
// simulator 1 and return `true` if successful or `false` if an error is 
// produced on the Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//  * number of Fourier transforms
//
// Each of the first two arguments must be of size `2*ft_size*n_ft`, where 
// `n_ft` is the third argument
EXT bool batched_ift_inplace_stable(unsigned int, const double*, double*, unsigned long);

// attempt to perform batched inplace inverse Fourier transforms without 
// rescalling and return `true` if successful or `false` if an error is 
// produced on the Rust side
//
// Arguments: 
//  * index of the simulator
//  * input array
//  * output array
//  * number of Fourier transforms
//
// Each of the first two arguments must be of size `2*ft_size*n_ft`, where 
// `n_ft` is the third argument
EXT bool batched_ift_inplace_stable_ns(unsigned int*, const double*, double*, unsigned long);

// attempt to perform batched periodic convolutions 
//
// Arguments: 
//  * index of the simulator
//  * left input array
//  * right input array
//  * number of convolutions
//
// The second and third arguments must be of size `2*ft_size*n_ft`, where `n_ft` 
// is the third argument
EXT double* batched_convolution(unsigned int, const double*, const double*, unsigned long);

// attempt to perform batched antiperiodic convolutions 
//
// Arguments: 
//  * index of the simulator
//  * left input array
//  * right input array
//  * number of convolutions
//
// The second and third arguments must be of size `2*ft_size*n_ft`, where `n_ft` 
// is the third argument
EXT double* batched_polymult(unsigned int, const double*, const double*, unsigned long);

// // set the numbers of levels and frames for the second frame splitting
EXT void set_n_levels_frames(unsigned int, unsigned long, unsigned long);

#endif
