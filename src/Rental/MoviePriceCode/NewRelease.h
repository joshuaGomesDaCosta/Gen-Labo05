//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_NEWRELEASE_H
#define GEN_LABO05_NEWRELEASE_H

#include "MoviePriceCode.h"

class NewRelease : public MoviePriceCode{
public:
    NewRelease();
    virtual double generateAmount(int rentalDays);
};

inline NewRelease::NewRelease()
:MoviePriceCode(0, 0, 3)
{}



inline double NewRelease::generateAmount(int rentalDays) {
    double amount = price;
    if(rentalDays - freeDays > 0)
        amount += (rentalDays-freeDays)*multiply;
    return amount;
}

#endif //GEN_LABO05_NEWRELEASE_H
