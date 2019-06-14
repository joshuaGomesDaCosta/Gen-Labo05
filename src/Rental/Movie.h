// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <memory>
#include "MoviePriceCode/MoviePriceCode.h"

class Movie {
public:
    virtual std::shared_ptr<MoviePriceCode> getPriceCode() const = 0;
    virtual void setPriceCode(std::shared_ptr<MoviePriceCode> arg) = 0;
    virtual std::string getTitle() const = 0;
    virtual ~Movie() {}
};

#endif // MOVIE_H