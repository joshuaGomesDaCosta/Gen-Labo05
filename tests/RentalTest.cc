
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>
#include <src/Rental/MovieImpl.h>
#include <src/Rental/RentalImpl.h>

#include "../src/Rental/Rental.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Regular.h"
#include "src/Rental/MoviePriceCode/Children.h"

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {
	RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar", std::shared_ptr<MoviePriceCode>(new Regular()))),10);
	ASSERT_EQ(rental.determineAmount(), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {
	RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar", std::shared_ptr<MoviePriceCode>(new NewRelease()))),10);
	ASSERT_EQ(rental.determineAmount(), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {
	RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar",std::shared_ptr<MoviePriceCode>(new Children()))),10);
	ASSERT_EQ(rental.determineAmount(), 12);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithChildren) {
    RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar",std::shared_ptr<MoviePriceCode>(new Children()))),10);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithMultipleDays) {
    RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar",std::shared_ptr<MoviePriceCode>(new NewRelease()))),2);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 2);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithOneDay) {
    RentalImpl rental = RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar",std::shared_ptr<MoviePriceCode>(new NewRelease()))),1);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}