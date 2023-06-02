#pragma once

#include <iterator>
#include <vector>

using namespace std;

namespace ariel{
    class MagicalContainer{
    private:
        vector<int> mystical_elements;
        int size1;

    public:
        MagicalContainer();
        void addElement(int new_element);
        void removeElement(int past_element);
        int size() const;
        ~MagicalContainer();

        // Ascending Iterator class
        class AscendingIterator{
        private:
            MagicalContainer& _container;
            size_t _idx;

        public:
            explicit AscendingIterator(MagicalContainer& container, size_t idx = 0);

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            AscendingIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // SideCross Iterator class
        class SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t _idx;

        public:
            explicit SideCrossIterator(MagicalContainer& container, size_t idx = 0);

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // Prime Iterator class
        class PrimeIterator {
        private:
            MagicalContainer& container;
            size_t _idx;

        public:
            explicit PrimeIterator(MagicalContainer& container, size_t idx = 0);

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            PrimeIterator operator++(int);
            int* begin() const;
            int* end() const;
        };
    };
}
