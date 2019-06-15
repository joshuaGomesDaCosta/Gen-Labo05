// RentalImpl.h
#ifndef GEN_LABO05_RENTALIMPL_H
#define GEN_LABO05_RENTALIMPL_H

#include "Rental.h"

class RentalImpl : public Rental {
public:
    RentalImpl(std::shared_ptr<Movie> movie, int daysRented );

    int getDaysRented() const;
    const std::shared_ptr<Movie> getMovie() const;
    double determineAmount() const;
    std::string streamPrint() const;
    int getFrequentRenterPoints() const;

private:
    std::shared_ptr<Movie> _movie;
    int _daysRented;
};

inline RentalImpl::RentalImpl( std::shared_ptr<Movie> movie, int daysRented )
        : _movie( std::move(movie))
        , _daysRented( daysRented ) {}

inline int RentalImpl::getDaysRented() const { return _daysRented; }

inline const std::shared_ptr<Movie> RentalImpl::getMovie() const { return _movie; }

inline double RentalImpl::determineAmount() const {
    return _movie->getPriceCode()->generateAmount(_daysRented);
}

inline std::string RentalImpl::streamPrint() const {
    std::stringstream ss("");
    ss << _movie->getTitle() << "\t" << determineAmount() << "\n";
    return ss.str();
}

inline int RentalImpl::getFrequentRenterPoints() const {
    int frequentRenterPoints = 1;

    frequentRenterPoints += _movie->getPriceCode()->getFrequentBonus(_daysRented);

    return frequentRenterPoints;
}

#endif //GEN_LABO05_RENTALIMPL_H
