//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_NEWRELEASE_H
#define GEN_LABO05_NEWRELEASE_H

#include "MoviePriceCode.h"

class NewRelease : public MoviePriceCode{
private:
    const double MULTIPLY = 3;
    const int DAYS_BONUS_FREQUENT = 1;
    const int BONUS = 1;
public:
    NewRelease();
    virtual double generateAmount(int rentalDays);
    int getFrequentBonus(int rentalDays);
};

inline NewRelease::NewRelease()
:MoviePriceCode()
{}

inline double NewRelease::generateAmount(int rentalDays) {
    return rentalDays * MULTIPLY;
}

inline int NewRelease::getFrequentBonus(int rentalDays) {
    if(rentalDays > DAYS_BONUS_FREQUENT)
        return BONUS;
    return 0;
}

#endif //GEN_LABO05_NEWRELEASE_H
