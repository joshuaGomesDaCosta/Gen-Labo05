//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_CHILDREN_H
#define GEN_LABO05_CHILDREN_H


#include "MoviePriceCode.h"

class Children : public MoviePriceCode{
public:
    Children();
    virtual double generateAmount(int rentalDays);
};

inline Children::Children()
:MoviePriceCode(3, 1.5, 1.5)
{}

inline double Children::generateAmount(int rentalDays) {
    double amount = price;
    if(rentalDays - freeDays > 0)
        amount += (rentalDays-freeDays)*multiply;
    return amount;
}


#endif //GEN_LABO05_CHILDREN_H
