// RentalTest.cc
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>
#include <src/Rental/RentalImpl.h>
#include <src/Rental/MovieMock.h>

#include "../src/Rental/Rental.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Regular.h"
#include "src/Rental/MoviePriceCode/Children.h"

using namespace std;
using ::testing::Return;

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> regular(new Regular());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(regular));

	RentalImpl rental = RentalImpl(movie, 10);
	ASSERT_EQ(rental.determineAmount(), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> newRelease(new NewRelease());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(newRelease));

	RentalImpl rental = RentalImpl(movie, 10);
	ASSERT_EQ(rental.determineAmount(), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> children(new Children());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(children));

	RentalImpl rental = RentalImpl(movie, 10);
	ASSERT_EQ(rental.determineAmount(), 12);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithChildren) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> children(new Children());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(children));

    RentalImpl rental = RentalImpl(movie, 10);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithMultipleDays) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> newRelease(new NewRelease());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(newRelease));

    RentalImpl rental = RentalImpl(movie, 2);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 2);
}

TEST(getFrequentRenterPoints, testReturnTheNumberOfFrequentRenterPointsWithNewReleaseWithOneDay) {

    shared_ptr<MovieMock> movie(new MovieMock);
    shared_ptr<MoviePriceCode> newRelease(new NewRelease());

    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(Return(newRelease));

    RentalImpl rental = RentalImpl(movie, 1);
    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}