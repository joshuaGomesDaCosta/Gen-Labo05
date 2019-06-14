// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <sstream>

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double determineAmount() const;
    std::string streamPrint() const;

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
    return _movie.getPriceCode()->generateAmount(_daysRented);
}

inline std::string Rental::streamPrint() const {
	std::stringstream ss("");
	ss << _movie.getTitle() << "\t" << determineAmount() << "\n";
	return ss.str();
}
#endif // RENTAL_H