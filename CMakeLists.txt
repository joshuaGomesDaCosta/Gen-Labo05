cmake_minimum_required(VERSION 2.8.2)
project(Gen_Labo05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gen_Labo05
		src/Customer.cpp
		src/Customer.h
		src/main.cpp
		src/Movie.cpp
		src/Movie.h
		src/Rental.h
		tests/CustomerTest.cc
)

add_subdirectory(lib/googletest-release-1.8.1)
include_directories(lib/googletest-release-1.8.1/googletest/include)
include_directories(lib/googletest-release-1.8.1/googlemock/include)
target_link_libraries(Gen_Labo05 gtest gtest_main)