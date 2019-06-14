//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_REGULAR_H
#define GEN_LABO05_REGULAR_H

#include "MoviePriceCode.h"

class Regular : public MoviePriceCode{
public:
    Regular();
    virtual double generateAmount(int rentalDays);
};

inline Regular::Regular()
:MoviePriceCode()
{}

inline double Regular::generateAmount(int rentalDays) {
    double amount = 2;
    if(rentalDays > 2)
        amount += (rentalDays-2)*1.5;
    return amount;
}

#endif //GEN_LABO05_REGULAR_H
