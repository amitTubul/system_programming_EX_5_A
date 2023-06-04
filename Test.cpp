#include "sources/MagicalContainer.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;


TEST_CASE("basic use") {
    MagicalContainer cont;
    SUBCASE("Magical Container") {
        CHECK_EQ(cont.size(), 0);
        cont.addElement(1);
        cont.addElement(2);
        cont.addElement(3);
        CHECK_EQ(cont.size(), 3);
        CHECK_NOTHROW(cont.removeElement(1));
        CHECK_THROWS(cont.removeElement(1));
        CHECK_EQ(cont.size(), 2);

    }
    SUBCASE("Ascending Iterator") {
        cont.addElement(2);
        cont.addElement(3);
        cont.addElement(1);
        MagicalContainer::AscendingIterator it(cont);
        CHECK_EQ(*it, 1);
        ++it;
        CHECK_EQ(*it, 2);
        ++it;
        CHECK_EQ(*it, 3);
    }
    SUBCASE("SideCross Iterator") {
        cont.addElement(2);
        cont.addElement(3);
        cont.addElement(1);
        MagicalContainer::SideCrossIterator it(cont);
        CHECK_EQ(*it, 1);
        ++it;
        CHECK_EQ(*it, 3);
        ++it;
        CHECK_EQ(*it, 2);
    }
    SUBCASE("Prime Iterator") {
        cont.addElement(2);
        cont.addElement(5);
        cont.addElement(7);
        cont.addElement(4);
        MagicalContainer::PrimeIterator it(cont);
        CHECK_EQ(*it, 2);
        ++it;
        CHECK_EQ(*it, 7);
        ++it;
        CHECK_EQ(*it, 5);
    }
}

TEST_CASE("large use") {
    MagicalContainer cont;
    SUBCASE("Magical Container") {
        CHECK_EQ(cont.size(), 0);
        for (int i = 0; i < 1000; ++i) {
            CHECK_NOTHROW(cont.addElement(i));
        }
        CHECK_EQ(cont.size(), 1000);
        CHECK_NOTHROW(cont.removeElement(0));
        CHECK_THROWS(cont.removeElement(0));
        for (int i = 1; i < 1000; ++i) {
            CHECK_NOTHROW(cont.removeElement(i));
        }
        CHECK_EQ(cont.size(), 0);
    }

    SUBCASE("Ascending Iterator") {
        for (int i = 0; i < 1000; ++i) {
            CHECK_NOTHROW(cont.addElement(i));
        }
        MagicalContainer::AscendingIterator it(cont);
        for (int i = 0; i < 1000; ++i) {
            CHECK_EQ(*it, i);
            ++it;
        }
    }
    SUBCASE("SideCross Iterator") {
        for (int i = 0; i < 1000; ++i) {
            CHECK_NOTHROW(cont.addElement(i));
        }
        MagicalContainer::SideCrossIterator it(cont);
        CHECK_EQ(*it,0);
        ++it;
        CHECK_EQ(*it,999);
    }
    SUBCASE("Prime Iterator") {
        for (int i = 0; i < 1000; ++i) {
            CHECK_NOTHROW(cont.addElement(i));
        }
        MagicalContainer::PrimeIterator it(cont);
        CHECK_EQ(*it,2);
        ++it;
        CHECK_EQ(*it,3);
        while(*it!=997)++it;
        CHECK_EQ(*it,997);
    }
}
