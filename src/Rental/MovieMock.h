#ifndef GEN_LABO05_MOVIEMOCK_H
#define GEN_LABO05_MOVIEMOCK_H

#include "gmock/gmock.h"
#include "Movie.h"

class MovieMock : public Movie {
public:
    MOCK_CONST_METHOD0(getPriceCode, std::shared_ptr<MoviePriceCode>());
    MOCK_METHOD1(setPriceCode, void(std::shared_ptr<MoviePriceCode>));
    MOCK_CONST_METHOD0(getTitle, std::string());
};

#endif //GEN_LABO05_MOVIEMOCK_H
