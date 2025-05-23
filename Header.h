#ifndef ITERATOR_HEADER
#define ITERATOR_HEADER
#include <cstdio>
#include <iterator>

template <typename T>
class Const_Iterator  {
        const T* ptr;
    public:
    //  override the usings here if needed  
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::random_access_iterator_tag;

        explicit Const_Iterator(pointer p);
        Const_Iterator(const Const_Iterator<T>& other);
        Const_Iterator& operator= (const Const_Iterator& other);
        reference operator*() const;
        pointer operator->() const;
        Const_Iterator& operator++();
        Const_Iterator operator++(int); //postfix
        Const_Iterator& operator--();
        Const_Iterator operator--(int); //postfix
        reference operator[](difference_type n) const;
        Const_Iterator operator+(difference_type n) const;
        Const_Iterator operator-(difference_type n) const;
        friend Const_Iterator operator+(difference_type n, const Const_Iterator& it); 
        difference_type operator-(const Const_Iterator& other) const;
        Const_Iterator& operator+=(difference_type n);
        Const_Iterator& operator-=(difference_type n);

        bool operator==(const Const_Iterator& other) const;
        bool operator!=(const Const_Iterator& other) const;
        bool operator<=(const Const_Iterator& other) const;
        bool operator>=(const Const_Iterator& other) const;
        bool operator>(const Const_Iterator& other) const;
        bool operator<(const Const_Iterator& other) const;

};

template <typename T>
class Iterator : public Const_Iterator {
        T* ptr;
    public:
//usings here at first 
        using reference = T&;
        using pointer =  T*;
        using difference_type = std::ptrdiff_t;
        
        Iterator(pointer);
        Iterator(const Iterator& other);
        reference operator*();
        pointer operator->();
        Iterator& operator++();
        Iterator operator++(int); //postfix
        Iterator& operator--();
        Iterator operator--(int); //postfix
        reference operator[](size_t n); // const ?
        Iterator operator+(difference_type n) const;
        friend Iterator operator+(difference_type n, Iterator& it);
        Iterator operator-(difference_type n) const;
        Iterator& operator+=(difference_type n);
        Iterator& operator-=(difference_type n);

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator<=(const Iterator& other) const;
        bool operator>=(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
};

template <typename Iter>
class Reverse_Iterator {
            Iter current;
    public:
            using iterator_type = Iter;
            using value_type = std::iterator_traits<Iter>::value_type;
            using iterator_category = std::iterator_traits<Iter>::iterator_category;
            using difference_type = std::iterator_traits<Iter>::difference_type;
            using reference = std::iterator_traits<Iter>::reference;
            using pointer = std::iterator_traits<Iter>::pointer;

            explicit Reverse_Iterator(Iter it);
            iterator_type base() const;
            Reverse_Iterator& operator= (const Reverse_Iterator& other);
            reference operator*() const;
            pointer operator->() const;
            reference operator[](difference_type index) const;
            Reverse_Iterator& operator++();
            Reverse_Iterator operator++(int);
            Reverse_Iterator operator+(difference_type n) const;
            Reverse_Iterator& operator+=(difference_type n);
            Reverse_Iterator& operator--();
            Reverse_Iterator operator--(int);
            difference_type operator-(difference_type n) const;
            Reverse_Iterator& operator-=(difference_type n);

};


#endif