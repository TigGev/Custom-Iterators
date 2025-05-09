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

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////REVERSE ITERATOR ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

template <class Iter>
Reverse_Iterator<Iter>::Reverse_Iterator(Iter it) : current(it) {}

template <class Iter>
Reverse_Iterator<Iter>::iterator_type Reverse_Iterator<Iter>::base() const {return current;}

template <class Iter>
Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator=(const Reverse_Iterator<Iter>& other) {current = other.current;}

template <class Iter>
Reverse_Iterator<Iter>::reference Reverse_Iterator<Iter>::operator*() const {return *(std::prev(current));}

template <class Iter>
Reverse_Iterator<Iter>::pointer Reverse_Iterator<Iter>::operator->() const {
      if constexpr (std::is_pointer_v<Iter>) {return current - 1;}
      else {return std::prev(current).operator->();}
}

template <class Iter> 
Reverse_Iterator<Iter>::reference Reverse_Iterator<Iter>::operator[](difference_type index) const {
      return *(std::prev(current, -index - 1));
}

template <class Iter>
Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator++() {
      --current;
      return *this;
}

template <class Iter>
Reverse_Iterator<Iter> Reverse_Iterator<Iter>::operator++(int) {
      Reverse_Iterator<Iter> tmp = *this;
      --current;
      return tmp;
}

template <class Iter>
Reverse_Iterator<Iter> Reverse_Iterator<Iter>::operator+(difference_type n) const {return Reverse_Iterator(current - n);}

template <class Iter>
Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator+=(difference_type n) {
      current -= n;
      return *this;
}

template <class Iter>
Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator--() {
      ++current;
      return this;
}

template <class Iter>
Reverse_Iterator<Iter> Reverse_Iterator<Iter>::operator--(int) {
      Reverse_Iterator tmp = *this;
      ++current;
      return tmp;
}

template <class Iter>
Reverse_Iterator<Iter>::difference_type Reverse_Iterator<Iter>::operator-(difference_type n) const {return Reverse_Iterator(current + n);}

template <class Iter>
Reverse_Iterator<Iter>& Reverse_Iterator<Iter>::operator-=(difference_type n) {
      current += n;
      return *this;
}

template <typename Iter>
bool operator==(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() == rhs.base();}

template <typename Iter>
bool operator!=(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() != rhs.base();}

template <typename Iter>
bool operator<=(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() <= rhs.base();}

template <typename Iter>
bool operator>=(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() >= rhs.base();}

template <typename Iter>
bool operator<(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() < rhs.base();}

template <typename Iter>
bool operator>(Reverse_Iterator<Iter> lhs, Reverse_Iterator<Iter> rhs) {return lhs.base() > rhs.base();}

template <typename Iter>
Reverse_Iterator<Iter> operator+(typename Reverse_Iterator<Iter>::difference_type n, Reverse_Iterator<Iter> it) { return it - n; }

template <typename Iter>
Reverse_Iterator<Iter> operator-(typename Reverse_Iterator<Iter>::difference_type n, Reverse_Iterator<Iter> it) { return it + n; }
