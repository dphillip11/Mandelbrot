cmake_minimum_required(VERSION 3.10)
project(Mandelbrot VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SOURCES "*.c")
file(GLOB HEADERS "*.h")

ADD_EXECUTABLE(Mandelbrot
    ./mandelbrot.c
    ${SOURCES}
    ${HEADERS}
)