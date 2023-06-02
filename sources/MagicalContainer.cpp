#include "MagicalContainer.hpp"

namespace ariel {

    int MagicalContainer::size() const{
        return 10;
    }

    void MagicalContainer::addElement(int new_element){
        //implementing just for first tests
        for (int idx:mystical_elements){
            if(idx==new_element)
                throw runtime_error("cant insert the same element again!");
        }
        mystical_elements.push_back(new_element);
    }

    void MagicalContainer::removeElement(int past_element){
        size1--;
    }

    MagicalContainer::MagicalContainer() {}

    MagicalContainer::~MagicalContainer() {}

    // Ascending 

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t idx)
            : _container(container), _idx(idx) {}

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return 999;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {
        return *this;
    }

    int* MagicalContainer::AscendingIterator::begin() const {
        return &(_container.mystical_elements[0]);
    }

    int* MagicalContainer::AscendingIterator::end() const {
        return &(_container.mystical_elements[0]);
    }


    // SideCross

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t idx)
            : container(container), _idx(idx) {}

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return 999;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {
        return *this;
    }

    int* MagicalContainer::SideCrossIterator::begin() const {
        return &(container.mystical_elements[0]);
    }

    int* MagicalContainer::SideCrossIterator::end() const {
        return &(container.mystical_elements[0]);
    }


    // Prime

    bool isPrime(int num) {
        return false;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t idx)
            : container(container), _idx(idx) {}

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return true;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) {
        return *this;
    }

    int* MagicalContainer::PrimeIterator::begin() const {
        return &(container.mystical_elements[0]);
    }

    int* MagicalContainer::PrimeIterator::end() const {
        return &(container.mystical_elements[0]);
    }
}
