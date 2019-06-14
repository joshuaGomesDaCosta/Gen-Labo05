// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <memory>
#include "MoviePriceCode/MoviePriceCode.h"
#include "MoviePriceCode/Regular.h"

class Movie {
public:

    Movie( const std::string& title, std::shared_ptr<MoviePriceCode> priceCode);

    std::shared_ptr<MoviePriceCode> getPriceCode() const;
    void setPriceCode(std::shared_ptr<MoviePriceCode> arg );
    std::string getTitle() const;

private:
    std::string _title;
    std::shared_ptr<MoviePriceCode> _priceCode;
};

inline Movie::
Movie( const std::string& title, std::shared_ptr<MoviePriceCode> priceCode )
        : _title( title )
        , _priceCode( std::move(priceCode))
{}

inline std::shared_ptr<MoviePriceCode> Movie::getPriceCode() const { return _priceCode; }

inline void Movie::setPriceCode(std::shared_ptr<MoviePriceCode> arg ) { _priceCode = std::move(arg); }

inline std::string Movie::getTitle() const { return _title; }

#endif // MOVIE_H