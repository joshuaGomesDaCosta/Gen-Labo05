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
:MoviePriceCode()
{}



inline double NewRelease::generateAmount(int rentalDays) {
    return rentalDays*3;
}

#endif //GEN_LABO05_NEWRELEASE_H
