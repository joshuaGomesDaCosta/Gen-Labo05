// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double determineAmount() const;
private:
    Movie _movie;
    int _daysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline const Movie& Rental::getMovie() const { return _movie; }

inline double Rental::determineAmount() const {
    double amount = 0;

    switch ( _movie.getPriceCode() ) {
        case Movie::REGULAR:
            amount += 2;
            if ( _daysRented > 2 )
                amount += ( _daysRented - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            amount += _daysRented * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if ( _daysRented > 3 )
                amount += ( _daysRented - 3 ) * 1.5;
            break;
    }

    return amount;
}

#endif // RENTAL_H