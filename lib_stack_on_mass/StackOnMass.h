// Copyright 2026 Lebedev Vladislav
#ifndef LIB_STACK_ON_MASS_STACKONMASS_H_
#define LIB_STACK_ON_MASS_STACKONMASS_H_

#include <stdexcept>

template<typename T>
class StackOnMass {
    T* _data;
    size_t _size;
    int _top;

 public:
    explicit StackOnMass(size_t size);
    StackOnMass(const StackOnMass& other);
    size_t get_size();
    int get_top();
    ~StackOnMass();
    void push(const T& num);
    inline T pop();
    inline T& top();
    inline bool is_empty() const noexcept;
    inline bool is_full() const noexcept;
};

template<typename T>
StackOnMass<T>::StackOnMass(size_t size) : _size(size), _top(-1) {
    _data = new T[_size];
}

template<typename T>
StackOnMass<T>::StackOnMass(const StackOnMass& other)
    : _size(other._size), _top(other._top) {
    _data = new T[_size];
    for (int i = 0; i <= _top; i++) {
        _data[i] = other._data[i];
    }
}

template<typename T>
size_t StackOnMass<T>::get_size() {
    return _size;
}

template<typename T>
int StackOnMass<T>::get_top() {
    return _top;
}

template<typename T>
StackOnMass<T>::~StackOnMass() {
    delete[] _data;
}

template<typename T>
void StackOnMass<T>::push(const T& num) {
    if (is_full()) {
        throw std::out_of_range("StackOnMass::push(): stack is full");
    } else {
        _data[++_top] = num;
    }
}

template<typename T>
inline T StackOnMass<T>::pop() {
    if (is_empty()) {
        throw std::out_of_range("StackOnMass::pop(): stack is empty");
    } else {
        return _data[_top--];
    }
}

template<typename T>
inline T& StackOnMass<T>::top() {
    if (is_empty()) {
        throw std::out_of_range("StackOnMass::top(): stack is empty");
    } else {
        return _data[_top];
    }
}

template<typename T>
inline bool StackOnMass<T>::is_empty() const noexcept {
    if (_top == -1) {
        return true;
    }
    return false;
}

template<typename T>
inline bool StackOnMass<T>::is_full() const noexcept {
    if (_top == static_cast<int>(_size) - 1) {
        return true;
    }
    return false;
}

#endif  // LIB_STACK_ON_MASS_STACKONMASS_H_
