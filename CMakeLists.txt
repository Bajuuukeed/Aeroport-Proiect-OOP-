cmake_minimum_required(VERSION 4.1)
project(OOP_Aeroport)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Aeroport main.cpp
        "Client .h"
        LinieAeriana.h
        Aeroport.h
        CabinCrew.h)
