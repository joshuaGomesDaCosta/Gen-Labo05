// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;

    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        Rental each = *iter;

        frequentRenterPoints += each.getFrequentRenterPoints();

        // show figures for this rental
        result << "\t" + each.streamPrint();
    }
    // add footer lines
    result << "Amount owed is " << getTotalAmount() << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

double Customer::getTotalAmount() const {
    double totalAmount = 0;

    auto iter = _rentals.begin();
    auto iter_end = _rentals.end();

    for( ; iter != iter_end; ++iter ){
        totalAmount += iter->determineAmount();
    }

    return totalAmount;
}