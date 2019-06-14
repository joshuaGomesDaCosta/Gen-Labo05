cmake_minimum_required(VERSION 2.8.2)

project(Gen-Labo05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gen_Labo05
		src/Customer.cpp
		src/Customer.h
		src/main.cpp
		src/Rental/Movie.cpp
		src/Rental/Movie.h
		src/Rental/Rental.h
		tests/CustomerTest.cc
		tests/RentalTest.cc
		tests/MoviePriceCode.cc
		src/Rental/MoviePriceCode/MoviePriceCode.h src/Rental/MoviePriceCode/Regular.h src/Rental/MoviePriceCode/Children.h src/Rental/MoviePriceCode/NewRelease.h)

add_subdirectory(lib/googletest-release-1.8.1)
include_directories(lib/googletest-release-1.8.1/googletest/include)
include_directories(lib/googletest-release-1.8.1/googlemock/include)
target_link_libraries(Gen_Labo05 gtest gtest_main)