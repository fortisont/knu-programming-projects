cmake_minimum_required(VERSION 3.13)
project(Intervals C)

set(CMAKE_C_STANDARD 99)

add_executable(Intervals main.c intervals.h intervals.c SetIntervals.h SetIntervals.c Inqeualty.h Inqeualty.c)