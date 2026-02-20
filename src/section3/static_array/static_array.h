#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N> class StaticArray
{
  private:
    T data[N]; // Fixed size contiguos memory

  public:
    // STL style iterator aliases
    using iterator       = T*;
    using const_iterator = const T*;

    StaticArray();

    // Direct access
    T&       operator[](std::size_t index);       // Non-Const version (modifiable)
    const T& operator[](std::size_t index) const; // Const version (read-only)

    // Safe Access
    T&       at(std::size_t index);
    const T& at(std::size_t index) const;

    // Utilities
    constexpr std::size_t size() const;
    void                  fill(const T& value);
    void                  print() const;
    void                  printMemLayout() const;

    // Iterator Support
    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;
};

#include "static_array.tpp"

#endif