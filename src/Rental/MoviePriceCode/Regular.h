// Regular.h
#ifndef GEN_LABO05_REGULAR_H
#define GEN_LABO05_REGULAR_H

#include "MoviePriceCode.h"

class Regular : public MoviePriceCode{
private:
    const double AMOUNT = 2;
    const int FREE_DAYS = 2;
    const double MULTIPLY = 1.5;
public:
    Regular();
    virtual double generateAmount(int rentalDays);
};

inline Regular::Regular()
:MoviePriceCode()
{}

inline double Regular::generateAmount(int rentalDays) {
    double amount = AMOUNT;
    if(rentalDays > FREE_DAYS)
        amount += (rentalDays-FREE_DAYS) * MULTIPLY;
    return amount;
}

#endif //GEN_LABO05_REGULAR_H
