#include "static_array.h"

template <typename T, std::size_t N>
inline StaticArray<T, N>::StaticArray()
{
    for (std::size_t i = 0; i < N; ++i)
    {
        data[i] = T();
    }
}

template <typename T, std::size_t N>
constexpr std::size_t StaticArray<T, N>::size() const
{
    return N;
}

template <typename T, std::size_t N>
T& StaticArray<T, N>::operator[](std::size_t index)
{
    return data[index];
}

template <typename T, std::size_t N>
const T& StaticArray<T, N>::operator[](std::size_t index) const
{
    return data[index];
}

template <typename T, std::size_t N>
const T& StaticArray<T, N>::at(std::size_t index) const
{
    if(index > N)
    {
       throw std::out_of_range("Index out of bounds");
    }

    return data[index];
}

template <typename T, std::size_t N>
void StaticArray<T, N>::fill(const T& value) {
     for(std::size_t i = 0; i < N; ++i) {
        data[i] = value;
    }
}

template <typename T, std::size_t N>
void StaticArray<T, N>::print() const {
    std::cout << "[ ";
    for(std::size_t i = 0; i < N; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

template <typename T, std::size_t N>
void StaticArray<T, N>::printMemLayout() const {
     for(std::size_t i = 0; i < N; ++i) {
        std::cout << "Index: " << i << " Address: " << &data[i] << std::endl;
    }
}