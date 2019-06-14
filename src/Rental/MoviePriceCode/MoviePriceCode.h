//
// Created by scout407 on 07.06.2019.
//

#ifndef GEN_LABO05_MOVIEPRICECODE_H
#define GEN_LABO05_MOVIEPRICECODE_H

class MoviePriceCode {
public:
    MoviePriceCode();
    virtual double generateAmount(int rentalDays) = 0;
};

inline MoviePriceCode::MoviePriceCode()
{}

#endif //GEN_LABO05_MOVIEPRICECODE_H
