cmake_minimum_required(VERSION 3.0)
include_directories(${GTEST_INCLUDE_DIRS})

set(CPP_EXAMPLES
        equality
        transforms
        )

foreach (FFT_PROCESSOR IN LISTS FFT_PROCESSORS)

    if (FFT_PROCESSOR STREQUAL "fftw")
        set(RUNTIME_LIBS
                tfhe-fftw
                ${FFTW_LIBRARIES}
                )

    else ()
        set(RUNTIME_LIBS
                tfhe-${FFT_PROCESSOR}
                )

    endif (FFT_PROCESSOR STREQUAL "fftw")

    foreach (CPP_EXAMPLE ${CPP_EXAMPLES})
        add_executable(${CPP_EXAMPLE}-${FFT_PROCESSOR} ${CPP_EXAMPLE}.cpp ${TFHE_HEADERS})
        target_link_libraries(${CPP_EXAMPLE}-${FFT_PROCESSOR} ${RUNTIME_LIBS})
    endforeach (CPP_EXAMPLE)

endforeach (FFT_PROCESSOR IN LISTS FFT_PROCESSORS) 
