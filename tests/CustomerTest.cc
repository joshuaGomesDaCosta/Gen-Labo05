
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>

#include "../src/Customer.h"

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

TEST(determineAmountsIntegration, testReturnForRentalWithRegularMovie) {
	Customer c;
	Rental rental = Rental(Movie("Avatar",Movie::REGULAR),10);
	ASSERT_EQ(c.determineAmounts(rental), 14);
}

TEST(determineAmountsIntegration, testReturnForRentalWithReleaseMovie) {
	Customer c;
	Rental rental = Rental(Movie("Avatar",Movie::NEW_RELEASE),10);
	ASSERT_EQ(c.determineAmounts(rental), 30);
}

TEST(determineAmountsIntegration, testReturnForRentalWithChildrensMovie) {
	Customer c;
	Rental rental = Rental(Movie("Avatar",Movie::CHILDRENS),10);
	ASSERT_EQ(c.determineAmounts(rental), 12);
}

TEST(statementIntegration, testReturnForEmptyRentals) {
	Customer c;
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \nAmount owed is 0\nYou earned 0 frequent renter points");
}

TEST(statementIntegration, testReturnForOneRentals) {
	Customer c;
	c.addRental(Rental(Movie("Avatar"),10));
	string statement = c.statement();
	ASSERT_EQ(statement, "Rental Record for \n\tAvatar\t14\nAmount owed is 14\nYou earned 1 frequent renter points");
}

TEST(statementIntegration, testReturnForManyRentalsWithDifferentPriceCode) {
	Customer c;
	c.addRental(Rental(Movie("Shrek",Movie::CHILDRENS),8));
	c.addRental(Rental(Movie("Inception"),12));
	c.addRental(Rental(Movie("Avatar2",Movie::NEW_RELEASE),20));
	string statement = c.statement();

	ASSERT_EQ(statement, "Rental Record for \n\tShrek\t9\n\tInception\t17\n\tAvatar2\t60\nAmount owed is 86\nYou earned 4 frequent renter points");
}
