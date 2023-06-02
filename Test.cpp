#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Test add_element and remove_element is affect the size") {
    MagicalContainer testcontainer;
    CHECK((testcontainer.size() == 0));

    testcontainer.addElement(20);
    CHECK((testcontainer.size() == 1));

    testcontainer.addElement(9);
    testcontainer.addElement(3);
    CHECK((testcontainer.size() == 3));

    //should not throw
    CHECK_THROWS(testcontainer.addElement(8));
    //should throw
    CHECK_THROWS(testcontainer.addElement(9));
    testcontainer.addElement(10);
    testcontainer.addElement(11);

    testcontainer.removeElement(9);
    CHECK((testcontainer.size() == 5));

    testcontainer.removeElement(8);
    testcontainer.removeElement(10);
    CHECK((testcontainer.size() == 3));
}

TEST_CASE("Test remove_element"){
    MagicalContainer testcontainer,testcontainer2;
    testcontainer.addElement(8);
    testcontainer.addElement(9);
    testcontainer.addElement(10);
    testcontainer.addElement(24);
    testcontainer.addElement(23);
    testcontainer.addElement(34);

    testcontainer.removeElement(8);
    CHECK((testcontainer.size() == 9));

    testcontainer.removeElement(9);
    CHECK((testcontainer.size() == 8));

    testcontainer.removeElement(10);
    CHECK((testcontainer.size() == 7));
}

TEST_CASE("Test bool expressions") {
    MagicalContainer testcontainer,testcontainer2;
    testcontainer.addElement(8);
    testcontainer.addElement(9);
    testcontainer.addElement(10);
    testcontainer2.addElement(24);
    testcontainer2.addElement(23);
    testcontainer2.addElement(34);

    MagicalContainer::PrimeIterator prime(testcontainer);
    auto a1 = prime.end();
    auto a2 = prime.begin();
    MagicalContainer::AscendingIterator ascend(testcontainer);
    auto b1 = ascend.begin();
    MagicalContainer::AscendingIterator ascend2(testcontainer2);
    auto b2 = ascend2.begin();
    bool bully;
    MagicalContainer::SideCrossIterator side(testcontainer);
    auto c = side.end();
    
    CHECK_NOTHROW(bully = (a1==a2));
    CHECK_NOTHROW(bully = (a1!=a2));
    CHECK_NOTHROW(bully = (a1>a2));
    CHECK_NOTHROW(bully = (a1<a2));

    CHECK_THROWS(bully = (a1==b2));
    CHECK_THROWS(bully = (a1!=b2));
    CHECK_THROWS(bully = (a1>b2));
    CHECK_THROWS(bully = (a1<b2));

    CHECK_THROWS(bully = (c==b2));
    CHECK_THROWS(bully = (c!=b2));
    CHECK_THROWS(bully = (c>b2));
    CHECK_THROWS(bully = (c<b2));

    CHECK_THROWS(bully = (b1==b2));
    CHECK_THROWS(bully = (b1!=b2));
    CHECK_THROWS(bully = (b1>b2));
    CHECK_THROWS(bully = (b1<b2));

}

TEST_CASE("Test AscendingIterator functionality") {
    MagicalContainer testcontainer;
    testcontainer.addElement(8);
    testcontainer.addElement(9);
    testcontainer.addElement(10);
    testcontainer.addElement(11);
    testcontainer.addElement(12);

    MagicalContainer::AscendingIterator tester(testcontainer);
    auto it = tester.begin();
    auto it2 = it;

    CHECK(*it == 8);
    CHECK(*it2== 8);

    it++;
    CHECK(*it == 9);
    CHECK((it > it2));
    CHECK((it2!=it));

    it2++;
    CHECK((it==it2));

    it++;
    CHECK((*it == 10));
    it++;
    CHECK((*it == 11));

    it2 = it;
    it2++;
    CHECK((it2 == tester.end()));

    //if we are in the end
    CHECK_THROWS((it2++));
}

TEST_CASE("Test SideCrossIterator functionality") {
    MagicalContainer testcontainer;
    testcontainer.addElement(8);
    testcontainer.addElement(9);
    testcontainer.addElement(10);
    testcontainer.addElement(11);
    testcontainer.addElement(12);

    MagicalContainer::SideCrossIterator tester(testcontainer);
    auto it = tester.begin();
    auto it2 = it;

    CHECK(*it == 8);
    CHECK(*it2== 8);

    it++;
    CHECK(*it == 9);
    CHECK((it > it2));
    CHECK((it2!=it));

    it2++;
    CHECK((it==it2));

    it++;
    CHECK((*it == 10));
    it++;
    CHECK((*it == 11));

    it2 = it;
    it2++;
    CHECK((it2 == tester.end()));

    //if we are in the end
    CHECK_THROWS((it2++));
}

TEST_CASE("Test PrimeIterator functionality") {
    MagicalContainer testcontainer;
    testcontainer.addElement(8);
    testcontainer.addElement(9);
    testcontainer.addElement(10);
    testcontainer.addElement(11);
    testcontainer.addElement(12);

    MagicalContainer::PrimeIterator tester(testcontainer);
    auto it = tester.begin();
    auto it2 = it;

    CHECK(*it == 8);
    CHECK(*it2== 8);

    it++;
    CHECK(*it == 9);
    CHECK((it > it2));
    CHECK((it2!=it));

    it2++;
    CHECK((it==it2));

    it++;
    CHECK((*it == 10));
    it++;
    CHECK((*it == 11));

    it2 = it;
    it2++;
    CHECK((it2 == tester.end()));

    //if we are in the end
    CHECK_THROWS((it2++));
}