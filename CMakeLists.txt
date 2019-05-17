cmake_minimum_required(VERSION 3.14)
project(Gen_Labo05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gen_Labo05
		src/Customer.cpp
		src/Customer.h
		src/main.cpp
		src/Movie.cpp
		src/Movie.h
		src/Rental.h)
