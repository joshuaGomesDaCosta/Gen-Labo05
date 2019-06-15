// RentalMock.h
#ifndef GEN_LABO05_RENTALMOCK_H
#define GEN_LABO05_RENTALMOCK_H

#include "gmock/gmock.h"
#include "Rental.h"

class RentalMock : public Rental {
public:
    MOCK_CONST_METHOD0(getDaysRented, int());
    MOCK_CONST_METHOD0(getMovie, const std::shared_ptr<Movie>());
    MOCK_CONST_METHOD0(determineAmount, double());
    MOCK_CONST_METHOD0(streamPrint, std::string());
    MOCK_CONST_METHOD0(getFrequentRenterPoints, int());
};

#endif //GEN_LABO05_RENTALMOCK_H
