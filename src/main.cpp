#include <iostream>

#include "Customer.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <src/Rental/MoviePriceCode/NewRelease.h>
#include <src/Rental/MoviePriceCode/Children.h>

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
