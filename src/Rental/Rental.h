// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <src/Rental/MoviePriceCode/NewRelease.h>
#include <sstream>

class Rental {
public:
    virtual int getDaysRented() const = 0;
    virtual const std::shared_ptr<Movie> getMovie() const = 0;
    virtual double determineAmount() const = 0;
    virtual std::string streamPrint() const = 0;
    virtual int getFrequentRenterPoints() const = 0;
    virtual ~Rental() {}
};

#endif // RENTAL_H