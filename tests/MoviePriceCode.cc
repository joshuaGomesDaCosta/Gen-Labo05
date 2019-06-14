
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "src/Rental/MoviePriceCode/MoviePriceCode.h"
#include "src/Rental/MoviePriceCode/Children.h"
#include "src/Rental/MoviePriceCode/Regular.h"
#include "src/Rental/MoviePriceCode/NewRelease.h"

TEST( generateAmountUnit, testReturnForRegularWith0To5Days) {
	for(int i = 0; i < 5; i++) {
		double amount = 2;
		if (i - 2 > 0)
			amount += (i - 2) * 1.5;
		ASSERT_EQ(Regular().generateAmount(i), amount);
	}
}

TEST( generateAmountUnit, testReturnForNewReleaseWith0To5Days) {
	for(int i = 0; i < 5; i++) {
		double amount = 3*i;
		ASSERT_EQ(NewRelease().generateAmount(i), amount);
	}
}

TEST( generateAmountUnit, testReturnForChildrenWith0To5Days) {
	for(int i = 0; i < 5; i++) {
		double amount = 1.5;
		if (i - 3 > 0)
			amount += (i - 3) * 1.5;
		ASSERT_EQ(Children().generateAmount(i), amount);
	}
}

TEST(getFrequentBonus, testReturnFrequentPointBonusNewRelease) {
    ASSERT_EQ(NewRelease().getFrequentBonus(1), 0);
    ASSERT_EQ(NewRelease().getFrequentBonus(3), 1);
}

TEST(getFrequentBonus, testReturnFrequentPointBonusChildren) {
    ASSERT_EQ(Children().getFrequentBonus(1), 0);
    ASSERT_EQ(Children().getFrequentBonus(3), 0);
}

TEST(getFrequentBonus, testReturnFrequentPointBonusForRegular) {
    ASSERT_EQ(Regular().getFrequentBonus(1), 0);
    ASSERT_EQ(Regular().getFrequentBonus(3), 0);
}
