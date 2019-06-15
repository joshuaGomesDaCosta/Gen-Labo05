// CustomerTest.cc
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>
#include <src/Rental/MovieImpl.h>
#include <src/Rental/RentalImpl.h>
#include <src/Rental/MoviePriceCode/Regular.h>
#include <src/Rental/MovieMock.h>
#include <src/Rental/RentalMock.h>

#include "../src/Customer.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Children.h"

using namespace std;
using ::testing::Return;
using ::testing::ReturnRef;

TEST(statementIntegration, testReturnForEmptyRentals) {
	Customer c;
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \nAmount owed is 0\nYou earned 0 frequent renter points");
}

TEST(statementIntegration, testReturnForOneRentals) {
	Customer c;
	c.addRental(std::shared_ptr<Rental>(new RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar", std::shared_ptr<MoviePriceCode>(new Regular()))),10)));
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \n\tAvatar\t14\nAmount owed is 14\nYou earned 1 frequent renter points");
}

TEST(statementIntegration, testReturnForManyRentalsWithDifferentPriceCode) {
	Customer c;
	c.addRental(std::shared_ptr<Rental>(new RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Shrek", std::shared_ptr<MoviePriceCode>(new Children()))),8)));
	c.addRental(std::shared_ptr<Rental>(new RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Inception", std::shared_ptr<MoviePriceCode>(new Regular()))),12)));
	c.addRental(std::shared_ptr<Rental>(new RentalImpl(std::shared_ptr<Movie>(new MovieImpl("Avatar2", std::shared_ptr<MoviePriceCode>(new NewRelease()))),20)));
	string statement = c.statement();

	ASSERT_EQ(statement, "Rental Record for \n\tShrek\t9\n\tInception\t17\n\tAvatar2\t60\nAmount owed is 86\nYou earned 4 frequent renter points");
}

TEST(getTotalAmount, testReturnTheRightTotalAmount) {
    Customer c;

    std::shared_ptr<RentalMock> rental1(new RentalMock());
    EXPECT_CALL(*rental1, determineAmount()).WillRepeatedly(Return(9));

    std::shared_ptr<RentalMock> rental2(new RentalMock());
    EXPECT_CALL(*rental2, determineAmount()).WillRepeatedly(Return(17));

    std::shared_ptr<RentalMock> rental3(new RentalMock());
    EXPECT_CALL(*rental3, determineAmount()).WillRepeatedly(Return(60));

    c.addRental(rental1);
    c.addRental(rental2);
    c.addRental(rental3);
    double totalAmount = c.getTotalAmount();

    ASSERT_EQ(totalAmount, 86);
}

TEST(getTotalAmount, testReturnTheRightTotalAmountWithEmptyRental) {
    Customer c;
    double totalAmount = c.getTotalAmount();

    ASSERT_EQ(totalAmount, 0.0);
}

TEST(getTotalAmount, testReturnTheRightTotalAmountWithOneRental) {
    Customer c;

    std::shared_ptr<RentalMock> rental(new RentalMock());
    EXPECT_CALL(*rental, determineAmount()).WillRepeatedly(Return(9));

    c.addRental(rental);
    double totalAmount = c.getTotalAmount();

    ASSERT_EQ(totalAmount, 9);
}

TEST(getTotalRenterPoint, testReturnTheRightTotalRenterPoint) {
    Customer c;

    std::shared_ptr<RentalMock> rental1(new RentalMock());
    EXPECT_CALL(*rental1, getFrequentRenterPoints()).WillRepeatedly(Return(1));

    std::shared_ptr<RentalMock> rental2(new RentalMock());
    EXPECT_CALL(*rental2, getFrequentRenterPoints()).WillRepeatedly(Return(1));

    std::shared_ptr<RentalMock> rental3(new RentalMock());
    EXPECT_CALL(*rental3, getFrequentRenterPoints()).WillRepeatedly(Return(2));

    c.addRental(rental1);
    c.addRental(rental2);
    c.addRental(rental3);
    int totalRenterPoint = c.getTotalRenterPoint();

    ASSERT_EQ(totalRenterPoint, 4);
}

TEST(getTotalRenterPoint, testReturnTheRightTotalRenterPointEmpty) {
    Customer c;
    int totalRenterPoint = c.getTotalRenterPoint();

    ASSERT_EQ(totalRenterPoint, 0);
}

TEST(getAllRentalPrint, testReturnTheRightGetAllRentalPrint) {
    Customer c;

    std::shared_ptr<RentalMock> rental1(new RentalMock());
    EXPECT_CALL(*rental1, streamPrint()).WillRepeatedly(Return("Shrek\t9\n"));

    std::shared_ptr<RentalMock> rental2(new RentalMock());
    EXPECT_CALL(*rental2, streamPrint()).WillRepeatedly(Return("Inception\t17\n"));

    std::shared_ptr<RentalMock> rental3(new RentalMock());
    EXPECT_CALL(*rental3, streamPrint()).WillRepeatedly(Return("Avatar2\t60\n"));

    c.addRental(rental1);
    c.addRental(rental2);
    c.addRental(rental3);
    string allRentalPrint = c.getAllRentalPrint();
    ASSERT_EQ(allRentalPrint, "\tShrek\t9\n\tInception\t17\n\tAvatar2\t60\n");
}

TEST(getAllRentalPrint, testReturnTheRightGetAllRentalPrintEmpty) {
    Customer c;
    string allRentalPrint = c.getAllRentalPrint();
    ASSERT_EQ(allRentalPrint, "");
}