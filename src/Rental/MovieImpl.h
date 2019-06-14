#ifndef GEN_LABO05_MOVIEIMPL_H
#define GEN_LABO05_MOVIEIMPL_H

#include "Movie.h"

class MovieImpl : public Movie {
public:

    MovieImpl(const std::string& title, std::shared_ptr<MoviePriceCode> priceCode);
    std::shared_ptr<MoviePriceCode> getPriceCode() const;
    void setPriceCode(std::shared_ptr<MoviePriceCode> arg);
    std::string getTitle() const;
private:
    std::string _title;
    std::shared_ptr<MoviePriceCode> _priceCode;
};

inline MovieImpl::
MovieImpl(const std::string& title, std::shared_ptr<MoviePriceCode> priceCode)
        : _title(title)
        , _priceCode(std::move(priceCode))
{}

inline std::shared_ptr<MoviePriceCode> MovieImpl::getPriceCode() const { return _priceCode; }

inline void MovieImpl::setPriceCode(std::shared_ptr<MoviePriceCode> arg) { _priceCode = std::move(arg); }

inline std::string MovieImpl::getTitle() const { return _title; }

#endif //GEN_LABO05_MOVIEIMPL_H
