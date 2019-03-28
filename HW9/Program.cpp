#include <iostream>
#include "Array.hpp"
#include <typeinfo>
#include <tuple>
#include <stdexcept>

template<class Type>
void print_values(Type value) {
    const Type* pt = &value;
    std::cout << typeid(*pt).name() << ": " << value << '\n';
}

template<class Type, class... Args>
void print_values(Type value, Args... args) {
    const Type* pt = &value;
    std::cout << typeid(*pt).name() << ": " << value << '\n';
    print_values(args...);
}

template<size_t F, size_t S, class... Type>
auto to_pair(const std::tuple<Type... >& tuple) -> decltype(std::make_pair(std::get<F>(tuple), std::get<S>(tuple))) {
    return std::make_pair(std::get<F>(tuple), std::get<S>(tuple));
}

int main() {
    print_values(0, 3.5, "Hello");
    std::cout << '\n';
    Array<int> first(3);
    Array<int> second = std::move(first);
    std::cout << second.size() << '\n';
    auto t = std::make_tuple(0, 3.5, "Hello world!");
    std::pair<double, char const *> p = to_pair<1, 2>(t);
    std::cout << p.first << ' ' << p.second;
    return 0;
}
