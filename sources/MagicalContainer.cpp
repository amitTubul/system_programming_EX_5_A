#include "MagicalContainer.hpp"
using namespace std;

namespace ariel{
    MagicalContainer::MagicalContainer() {}

    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int element) {
        auto it = lower_bound(_mysticalElements.begin(),_mysticalElements.end(),element);
        _mysticalElements.insert(it,element);
    }

    void MagicalContainer::removeElement(int element) {
        auto i=find(_mysticalElements.begin(),_mysticalElements.end(),element);
        if(i!=_mysticalElements.end())_mysticalElements.erase(i);
        else{throw runtime_error("element did not found");}
    }

    int MagicalContainer::size() const {return _mysticalElements.size();}



    // for AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator() {}
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container):_container(&container),_position(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator const &other):
        _container(other._container),_position(other._position){}
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator&
    MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator other) {
        if(this!=&other){
            this->_container=other._container;
            this->_position=other._position;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(MagicalContainer::AscendingIterator &other) const {
        return _position==other._position;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
        return _position!=other._position;
    }

    bool MagicalContainer::AscendingIterator::operator<(MagicalContainer::AscendingIterator &other) const {
        return _position<other._position;
    }

    bool MagicalContainer::AscendingIterator::operator>(MagicalContainer::AscendingIterator &other) const {
        return _position>other._position;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return _container->_mysticalElements.at(_position);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()  {
        ++_position;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return MagicalContainer::AscendingIterator(*_container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        MagicalContainer::AscendingIterator it(*_container);
        it._position=_container->_mysticalElements.size();
        return it;
    }



    // for SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator() {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container):_container(&container),_position(0) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator const &other):
            _container(other._container),_position(other._position){}
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator&
    MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator other) {
        if(this!=&other){
            this->_container=other._container;
            this->_position=other._position;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(MagicalContainer::SideCrossIterator &other) const {
        return _position==other._position;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
        return _position!=other._position;
    }

    bool MagicalContainer::SideCrossIterator::operator<(MagicalContainer::SideCrossIterator &other) const {
        return _position<other._position;
    }

    bool MagicalContainer::SideCrossIterator::operator>(MagicalContainer::SideCrossIterator &other) const {
        return _position>other._position;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return _container->_mysticalElements.at(_position);
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()  {
        ++_position;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return MagicalContainer::SideCrossIterator(*_container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        MagicalContainer::SideCrossIterator it(*_container);
        it._position=_container->_mysticalElements.size();
        return it;
    }

    // for PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator() {}
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container):_container(&container),_position(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator const &other):
            _container(other._container),_position(other._position){}
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator&
    MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator other) {
        if(this!=&other){
            this->_container=other._container;
            this->_position=other._position;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(MagicalContainer::PrimeIterator &other) const {
        return _position==other._position;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
        return _position!=other._position;
    }

    bool MagicalContainer::PrimeIterator::operator<(MagicalContainer::PrimeIterator &other) const {
        return _position<other._position;
    }

    bool MagicalContainer::PrimeIterator::operator>(MagicalContainer::PrimeIterator &other) const {
        return _position>other._position;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return _container->_mysticalElements.at(_position);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()  {
        ++_position;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return MagicalContainer::PrimeIterator(*_container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        MagicalContainer::PrimeIterator it(*_container);
        it._position=_container->_mysticalElements.size();
        return it;
    }

}