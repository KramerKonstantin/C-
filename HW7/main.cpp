#include <iostream>
#include "Array.h"

template<class T, class C>
T minimum(const Array<T>&  array, C compare) {
    sz size = array.size();
    if (size == 0) return T();
    T min = array[0];
    for (sz i = 0; i < size; i++) {
        if (compare(array[i], min)) {
            min = array[i];
        }
    }
    return min;
}

template<class T>
void flatten(const T& value, std::ostream& writer) {
    writer << value << " ";
}

template<class T>
void flatten(const Array<T>& array, std::ostream& writer) {
    for (sz i = 0; i < array.size(); i++) {
        flatten(array[i], writer);
    }
}

bool less(int a, int b) { return a < b; }

struct Greater { bool operator()(int a, int b) const { return b < a; } };

int main() {
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less);
    int max = minimum(ints, Greater());
    std::cout << min << " " << max << std::endl;

    Array<int> ints2(2, 0);
    ints2[0] = 10;
    ints2[1] = 20;
    flatten(ints2, std::cout);
    std::cout << std::endl;

    Array<Array<int>> array_of_ints(2, ints2);
    flatten(array_of_ints, std::cout);
    std::cout << std::endl;

    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout);
    std::cout << std::endl;
    return 0;
}