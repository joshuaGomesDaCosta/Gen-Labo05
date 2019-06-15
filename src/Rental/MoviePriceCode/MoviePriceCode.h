// MoviePriceCode.h
#ifndef GEN_LABO05_MOVIEPRICECODE_H
#define GEN_LABO05_MOVIEPRICECODE_H

class MoviePriceCode {
public:
    MoviePriceCode();
    virtual double generateAmount(int rentalDays) = 0;

    virtual int getFrequentBonus(int rentalDays);
};

inline MoviePriceCode::MoviePriceCode()
{}

inline int MoviePriceCode::getFrequentBonus(int rentalDays) {
    return 0;
}

#endif //GEN_LABO05_MOVIEPRICECODE_H
