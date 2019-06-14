
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>

#include "../src/Rental/Rental.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Regular.h"
#include "src/Rental/MoviePriceCode/Children.h"

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {
	Rental rental = Rental(Movie("Avatar", std::shared_ptr<MoviePriceCode>(new Regular())),10);
	ASSERT_EQ(rental.determineAmount(), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {
	Rental rental = Rental(Movie("Avatar", std::shared_ptr<MoviePriceCode>(new NewRelease())),10);
	ASSERT_EQ(rental.determineAmount(), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {
	Rental rental = Rental(Movie("Avatar",std::shared_ptr<MoviePriceCode>(new Children())),10);
	ASSERT_EQ(rental.determineAmount(), 12);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithChildren) {
    Rental rental = Rental(Movie("Avatar",std::shared_ptr<MoviePriceCode>(new Children())),10);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithMultipleDays) {
    Rental rental = Rental(Movie("Avatar",std::shared_ptr<MoviePriceCode>(new NewRelease())),2);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 2);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithOneDay) {
    Rental rental = Rental(Movie("Avatar",std::shared_ptr<MoviePriceCode>(new NewRelease())),1);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}