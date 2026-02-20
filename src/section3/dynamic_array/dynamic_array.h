#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T> class DynamicArray
{
  private:
    T*          data;       // Pointer to heap memory
    std::size_t m_size;     // Number of elements stored
    std::size_t m_capacity; // Allocated space

    void resize(std::size_t newCapacity);

  public:
    // STL style iterator aliases
    using iterator       = T*;
    using const_iterator = const T*;

    DynamicArray();
    explicit DynamicArray(std::size_t capacity);
    ~DynamicArray();

    // Utilties
    std::size_t size() const;
    std::size_t capacity() const;
    bool        is_empty() const;
    void        print() const;
    void        printMemLayout() const;

    // Modifiers
    void push(const T& value);
    T    pop();
    void clear();

    // Direct access
    T&       operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    // Safe access
    T&       at(std::size_t index);
    const T& at(std::size_t index) const;

    // Iterator support
    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;

    // Copy Constructor

    // Copy Assignment
};

#include "dynamic_array.tpp"

#endif