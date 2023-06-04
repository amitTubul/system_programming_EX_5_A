#ifndef SYSTEM_PROGRAMMING_EX_5_A_MAGICALCONTAINER_HPP
#define SYSTEM_PROGRAMMING_EX_5_A_MAGICALCONTAINER_HPP
#include <vector>
#include <algorithm>
#include <iostream>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> _mysticalElements;

    public:
        MagicalContainer();

        ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        int size() const;

        class AscendingIterator {
        private:
            const MagicalContainer *_container;
            size_t _position;
        public:
            AscendingIterator();

            explicit AscendingIterator(const MagicalContainer& container);

            AscendingIterator(AscendingIterator const &iterator);

            ~AscendingIterator();

            AscendingIterator & operator=(AscendingIterator other);

            bool operator==(AscendingIterator& other) const;

            bool operator!=(const AscendingIterator& other) const;

            bool operator<(AscendingIterator& other) const;

            bool operator>(AscendingIterator& other) const;

            int operator*()const;

            AscendingIterator& operator++();

            AscendingIterator begin();

            AscendingIterator end();
        };


        class SideCrossIterator {
        private:
            const MagicalContainer *_container;
            size_t _position;

        public:
            SideCrossIterator();

            SideCrossIterator(SideCrossIterator const &other);

            explicit SideCrossIterator(const MagicalContainer& container);

            ~SideCrossIterator();

            SideCrossIterator &operator=(SideCrossIterator other);

            bool operator==(SideCrossIterator& other) const;

            bool operator!=(const SideCrossIterator& other) const;

            bool operator<(SideCrossIterator& other) const;

            bool operator>(SideCrossIterator& other) const;

            int operator*()const;

            SideCrossIterator& operator++();

            SideCrossIterator begin();

            SideCrossIterator end();
        };

        class PrimeIterator {
        private:
            const MagicalContainer *_container;
            size_t _position;

        public:
            PrimeIterator();

            PrimeIterator(PrimeIterator const &other);

            explicit PrimeIterator(const MagicalContainer& container);

            ~PrimeIterator();

            PrimeIterator &operator=(PrimeIterator other);

            bool operator==(PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const;

            bool operator<(PrimeIterator& other) const;

            bool operator>(PrimeIterator& other) const;

            int operator*()const;

            PrimeIterator& operator++();

            PrimeIterator begin();

            PrimeIterator end();

        };
    };
}



#endif //SYSTEM_PROGRAMMING_EX_5_A_MAGICALCONTAINER_HPP
