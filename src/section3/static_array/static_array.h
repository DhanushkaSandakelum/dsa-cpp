#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray
{
private:
    T data[N]; // Fixed size contiguos memory

public:
    StaticArray();

    // Get Size
    constexpr std::size_t size() const;

    // Modify/Access Element
    T& operator[](std::size_t index); // Non-Const version (modifiable)
    const T& operator[](std::size_t index) const; // Const version (read-only)

    // Access Element with bound check
    const T& at(std::size_t index) const;

    // Fill Array with a given value
    void fill(const T& value);

    // Print Elements
    void print() const;

    // Print Memory Layout
    void printMemLayout() const;
};

#include "static_array.tpp"

#endif