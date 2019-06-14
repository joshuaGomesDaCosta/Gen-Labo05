// Customer.cpp
#include <sstream>
#include <vector>
#include <src/Rental/MoviePriceCode/NewRelease.h>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;

    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        Rental each = *iter;
        double thisAmount = each.determineAmount();

        // add frequent renter points
        frequentRenterPoints++;

        // add bonus for a two day new release rental
        if (dynamic_cast<NewRelease*>(each.getMovie().getPriceCode()) && each.getDaysRented() > 1 )
            frequentRenterPoints++;

        // show figures for this rental
        result << "\t" + each.streamPrint();
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}