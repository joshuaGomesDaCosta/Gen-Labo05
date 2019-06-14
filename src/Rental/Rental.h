// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <src/Rental/MoviePriceCode/NewRelease.h>
#include <sstream>

class Rental {
public:
    Rental( std::shared_ptr<Movie> movie, int daysRented );

    int getDaysRented() const;
    const std::shared_ptr<Movie> getMovie() const;
    double determineAmount() const;
    std::string streamPrint() const;
    int getFrequentRenterPoints() const;

private:
    std::shared_ptr<Movie> _movie;
    int _daysRented;
};

inline Rental::Rental( std::shared_ptr<Movie> movie, int daysRented )
        : _movie( std::move(movie))
        , _daysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline const std::shared_ptr<Movie> Rental::getMovie() const { return _movie; }

inline double Rental::determineAmount() const {
    return _movie->getPriceCode()->generateAmount(_daysRented);
}

inline std::string Rental::streamPrint() const {
	std::stringstream ss("");
	ss << _movie->getTitle() << "\t" << determineAmount() << "\n";
	return ss.str();
}

inline int Rental::getFrequentRenterPoints() const {
    int frequentRenterPoints = 1;

    frequentRenterPoints += _movie->getPriceCode()->getFrequentBonus(_daysRented);

    return frequentRenterPoints;
}

#endif // RENTAL_H