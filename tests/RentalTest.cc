
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>

#include "../src/Rental/Rental.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Regular.h"
#include "src/Rental/MoviePriceCode/Children.h"

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {
	Rental rental = Rental(Movie("Avatar", new Regular()),10);
	ASSERT_EQ(rental.determineAmount(), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {
	Rental rental = Rental(Movie("Avatar", new NewRelease()),10);
	ASSERT_EQ(rental.determineAmount(), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {
	Rental rental = Rental(Movie("Avatar", new Children()),10);
	ASSERT_EQ(rental.determineAmount(), 12);
}