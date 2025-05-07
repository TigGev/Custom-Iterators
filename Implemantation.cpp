#include <Header.h>
#include <cstdio>

//////////////////////////////////////// CONST ITERATOR ////////////////////////////////////////////////
template <typename T>
Const_Iterator<T>::Const_Iterator(pointer p) : ptr(p) {}

template <typename T>
Const_Iterator<T>::Const_Iterator(const Const_Iterator<T>& other) : Const_Iterator(other.ptr) {}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator= (const Const_Iterator<T>& other) {
    ptr = other.ptr;
    return *this;
}

template <typename T>
typename Const_Iterator<T>::reference Const_Iterator<T>::operator*() const {return *ptr;}

template <typename T>
typename Const_Iterator<T>::pointer Const_Iterator<T>::operator->() const {return ptr;}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator++() {
    ++ptr;
    return *this;
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator++(int) {
    Const_Iterator tmp(*this);
    ++ptr;
    return tmp;
}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator--() {
    --ptr;
    return *this;
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator--(int) {
    Const_Iterator tmp(*this);
    --ptr;
    return tmp;    
}

template <typename T>
typename Const_Iterator<T>::reference Const_Iterator<T>::operator[](typename Const_Iterator<T>::difference_type n) const {
    return *(ptr + n);
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator+(difference_type n) const { return Const_Iterator(ptr + n);}

template <typename T>
Const_Iterator<T> operator+(typename Const_Iterator<T>::difference_type n, const Const_Iterator<T>& it) {
    return Const_Iterator<T>(it.ptr + n);
}

template <typename T>
Const_Iterator<T> Const_Iterator<T>::operator-(difference_type n) const {
    return Const_Iterator<T>(ptr - n);
}

template <typename T>
typename  Const_Iterator<T>::difference_type Const_Iterator<T>::operator-(const Const_Iterator<T>& other) const {
    return ptr - other.ptr;
}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator+=(difference_type n) {
    ptr += n;
    return *this;
}

template <typename T>
Const_Iterator<T>& Const_Iterator<T>::operator-=(difference_type n) {
    ptr -= n;
    return *this;
}



template <typename T>
bool Const_Iterator<T>::operator==(const Const_Iterator<T>& other) const {
    return ptr == other.ptr;
}

template <typename T>
bool Const_Iterator<T>::operator!=(const Const_Iterator<T>& other) const {
    return ptr != other.ptr;
}

template <typename T>
bool Const_Iterator<T>::operator<=(const Const_Iterator<T>& other) const {
    return ptr <= other.ptr;
}

template <typename T>
bool Const_Iterator<T>::operator>=(const Const_Iterator<T>& other) const {
    return ptr >= other.ptr;
}

template <typename T>
bool Const_Iterator<T>::operator<(const Const_Iterator<T>& other) const {
    return ptr < other.ptr;
}

template <typename T>
bool Const_Iterator<T>::operator>(const Const_Iterator<T>& other) const {
    return ptr > other.ptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  ITERATOR /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
Iterator<T>::Iterator(pointer p) : Const_Iterator(p) {}

template <typename T>
Iterator<T>::Iterator(const Iterator<T>& other) : Const_Iterator(other.ptr) {}

template <typename T>
Iterator<T>::reference Iterator<T>::operator*() {return const_cast<reference>(*(static_cast<Const_Iterator&>(*this)));}

template <typename T>
Iterator<T>::pointer Iterator<T>::operator->() {return const_cast<pointer>(static_cast<Const_Iterator&>(*this).operator->());}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    ++ptr;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator tmp(*this);
    ++ptr;
    return tmp;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--() {
    --ptr;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator tmp(*this);
    --ptr;
    return tmp;
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](size_t n) {
    return const_cast<reference>(static_cast<Const_Iterator&>(*this)[n]);
}

template <typename T>
Iterator<T> Iterator<T>::operator+(difference_type n) const {
    return Iterator<T>(ptr + n);
}

template <typename T>
Iterator<T> operator+(typename Iterator<T>::difference_type n, Iterator<T>& it) {
    return it + n;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(difference_type n) const {
    return Iterator<T>(ptr - n);
}

template <typename T>
Iterator<T>& Iterator<T>::operator+=(difference_type n) {
    ptr += n;
    return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator-=(difference_type n) {
    ptr -= n;
    return *this;
}
template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) == static_cast<Const_Iterator&>(other)}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) != static_cast<Const_Iterator&>(other)}

template <typename T>
bool Iterator<T>::operator<=(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) <= static_cast<Const_Iterator&>(other)}

template <typename T>
bool Iterator<T>::operator>=(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) >= static_cast<Const_Iterator&>(other)}

template <typename T>
bool Iterator<T>::operator>(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) > static_cast<Const_Iterator&>(other)}

template <typename T>
bool Iterator<T>::operator<(const Iterator<T>& other) const {return static_cast<Const_Iterator&>(*this) < static_cast<Const_Iterator&>(other)}

