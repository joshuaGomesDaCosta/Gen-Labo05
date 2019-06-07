
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>

#include "../src/Rental.h"

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {
	Rental rental = Rental(Movie("Avatar",Movie::REGULAR),10);
	ASSERT_EQ(rental.determineAmount(), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {
	Rental rental = Rental(Movie("Avatar",Movie::NEW_RELEASE),10);
	ASSERT_EQ(rental.determineAmount(), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {
	Rental rental = Rental(Movie("Avatar",Movie::CHILDRENS),10);
	ASSERT_EQ(rental.determineAmount(), 12);
}