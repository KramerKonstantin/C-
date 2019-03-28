cmake_minimum_required(VERSION 3.10)
project(hw8)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw8 Headers/Animal.h Headers/Bear.h Headers/Man.h Headers/ManBearPig.h Headers/Pig.h Headers/Unit.h
        SourceFiles/Animal.cpp SourceFiles/Bear.cpp SourceFiles/Man.cpp SourceFiles/ManBearPig.cpp SourceFiles/Pig.cpp
        SourceFiles/Unit.cpp Program.cpp)

