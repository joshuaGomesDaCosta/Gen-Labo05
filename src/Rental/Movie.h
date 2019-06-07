// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "src/Rental/MoviePriceCode/MoviePriceCode.h"
#include "src/Rental/MoviePriceCode/Regular.h"

class Movie {
public:

    Movie( const std::string& title, MoviePriceCode* priceCode = new Regular());

    MoviePriceCode* getPriceCode() const;
    void setPriceCode(MoviePriceCode* arg );
    std::string getTitle() const;

private:
    std::string _title;
    MoviePriceCode* _priceCode;
};

inline Movie::
Movie( const std::string& title, MoviePriceCode* priceCode )
        : _title( title )
        , _priceCode( priceCode )
{}

inline MoviePriceCode* Movie::getPriceCode() const { return _priceCode; }

inline void Movie::setPriceCode(MoviePriceCode* arg ) { _priceCode = arg; }

inline std::string Movie::getTitle() const { return _title; }

#endif // MOVIE_H