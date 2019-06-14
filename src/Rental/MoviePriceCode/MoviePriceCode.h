//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_MOVIEPRICECODE_H
#define GEN_LABO05_MOVIEPRICECODE_H

class MoviePriceCode {
protected:
    int freeDays;
    double price;
    double multiply;
public:
    MoviePriceCode(int freeDays, double price, double multiply);
    virtual double generateAmount(int rentalDays) = 0;
};

inline MoviePriceCode::MoviePriceCode(int freeDays, double price, double multiply)
:freeDays(freeDays), price(price), multiply(multiply)
{}

#endif //GEN_LABO05_MOVIEPRICECODE_H
