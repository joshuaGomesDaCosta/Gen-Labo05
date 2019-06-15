// Children.h
#ifndef GEN_LABO05_CHILDREN_H
#define GEN_LABO05_CHILDREN_H


#include "MoviePriceCode.h"

class Children : public MoviePriceCode{
private:
    const double AMOUNT = 1.5;
    const int FREE_DAYS = 3;
    const double MULTIPLY = 1.5;
public:
    Children();
    virtual double generateAmount(int rentalDays);
};

inline Children::Children()
:MoviePriceCode()
{}

inline double Children::generateAmount(int rentalDays) {
    double amount = AMOUNT;
    if(rentalDays > FREE_DAYS)
        amount += (rentalDays-FREE_DAYS)*MULTIPLY;
    return amount;
}


#endif //GEN_LABO05_CHILDREN_H
