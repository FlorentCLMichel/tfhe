cmake_minimum_required(VERSION 3.0)

set(SRCS
    fft_processor_graphec.cpp
    lagrangehalfc_impl.cpp
    )

set(HEADERS
    lagrangehalfc_impl.h
    )

add_library(tfhe-fft-graphec OBJECT ${SRCS} ${HEADERS})
set_property(TARGET tfhe-fft-graphec PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(tfhe-fft-graphec STATIC "${CMAKE_CURRENT_SOURCE_DIR}/libproto_graphec.a")
