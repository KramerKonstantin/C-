#pragma once

#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <cstdio>

typedef size_t sz;

template<class T>
class Array {
public:
    explicit Array(sz size = 0, const T& value = T());
    Array(const Array& array);
    ~Array();
    Array& operator=(const Array& other);
    sz size() const;
    T& operator[] (sz index);
    const T& operator[](sz index) const;
private:
    T* mData;
    sz mSize;
    void copy(const Array& other);
};

#endif

#include "Array.cpp"