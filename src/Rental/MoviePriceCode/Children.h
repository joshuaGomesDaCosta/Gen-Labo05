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
:MoviePriceCode()
{}

inline double Children::generateAmount(int rentalDays) {
    double amount = 1.5;
    if(rentalDays > 3)
        amount += (rentalDays-3)*1.5;
    return amount;
}


#endif //GEN_LABO05_CHILDREN_H
