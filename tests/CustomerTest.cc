
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>

#include "../src/Customer.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"
#include "src/Rental/MoviePriceCode/Children.h"

using namespace std;
/*
class CustomerTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		Customer c;
	}
 
 virtual void TearDown() {}
};
*/

TEST(statementIntegration, testReturnForEmptyRentals) {
	Customer c;
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \nAmount owed is 0\nYou earned 0 frequent renter points");
}

TEST(statementIntegration, testReturnForOneRentals) {
	Customer c;
	c.addRental(Rental(Movie("Avatar", std::shared_ptr<MoviePriceCode>(new Regular())),10));
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \n\tAvatar\t14\nAmount owed is 14\nYou earned 1 frequent renter points");
}

TEST(statementIntegration, testReturnForManyRentalsWithDifferentPriceCode) {
	Customer c;
	c.addRental(Rental(Movie("Shrek", std::shared_ptr<MoviePriceCode>(new Children())),8));
	c.addRental(Rental(Movie("Inception", std::shared_ptr<MoviePriceCode>(new Regular())),12));
	c.addRental(Rental(Movie("Avatar2", std::shared_ptr<MoviePriceCode>(new NewRelease())),20));
	string statement = c.statement();

	ASSERT_EQ(statement, "Rental Record for \n\tShrek\t9\n\tInception\t17\n\tAvatar2\t60\nAmount owed is 86\nYou earned 4 frequent renter points");
}

TEST(getTotalAmount, testReturnTheRightTotalAmount) {
    Customer c;
    c.addRental(Rental(Movie("Shrek", std::shared_ptr<MoviePriceCode>(new Children())),8));
    c.addRental(Rental(Movie("Inception", std::shared_ptr<MoviePriceCode>(new Regular())),12));
    c.addRental(Rental(Movie("Avatar2", std::shared_ptr<MoviePriceCode>(new NewRelease())),20));
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
    c.addRental(Rental(Movie("Shrek", std::shared_ptr<MoviePriceCode>(new Children())),8));
    double totalAmount = c.getTotalAmount();

    ASSERT_EQ(totalAmount, 9);
}

TEST(getTotalRenterPoint, testReturnTheRightTotalRenterPoint) {
    Customer c;
    c.addRental(Rental(Movie("Shrek", std::shared_ptr<MoviePriceCode>(new Children())),8));
    c.addRental(Rental(Movie("Inception", std::shared_ptr<MoviePriceCode>(new Regular())),12));
    c.addRental(Rental(Movie("Avatar2", std::shared_ptr<MoviePriceCode>(new NewRelease())),20));
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
    c.addRental(Rental(Movie("Shrek", std::shared_ptr<MoviePriceCode>(new Children())),8));
    c.addRental(Rental(Movie("Inception", std::shared_ptr<MoviePriceCode>(new Regular())),12));
    c.addRental(Rental(Movie("Avatar2", std::shared_ptr<MoviePriceCode>(new NewRelease())),20));
    string allRentalPrint = c.getAllRentalPrint();
    ASSERT_EQ(allRentalPrint, "\tShrek\t9\n\tInception\t17\n\tAvatar2\t60\n");
}

TEST(getAllRentalPrint, testReturnTheRightGetAllRentalPrintEmpty) {
    Customer c;
    string allRentalPrint = c.getAllRentalPrint();
    ASSERT_EQ(allRentalPrint, "");
}