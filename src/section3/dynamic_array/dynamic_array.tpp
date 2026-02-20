#include "dynamic_array.h"

template <typename T> DynamicArray<T>::DynamicArray() : data{nullptr}, m_size(0), m_capacity(0)
{
}

template <typename T>
DynamicArray<T>::DynamicArray(std::size_t capacity) : data{nullptr}, m_size(0), m_capacity(capacity)
{
    data = new T[m_capacity];
}

template <typename T> DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template <typename T> std::size_t DynamicArray<T>::size() const
{
    return m_size;
}

template <typename T> std::size_t DynamicArray<T>::capacity() const
{
    return m_capacity;
}

template <typename T> bool DynamicArray<T>::is_empty() const
{
    return m_size == 0;
}

template <typename T> void DynamicArray<T>::resize(std::size_t newCapacity)
{
    // Allocate new larger block of memory
    T* newData = new T[newCapacity];

    // Copy existing elements to newData
    for (std::size_t i = 0; i < m_size; ++i)
    {
        newData[i] = data[i];
    }

    // Delete old memory
    delete[] data;

    // Redirect the pointer
    data       = newData;
    m_capacity = newCapacity;
}

template <typename T> void DynamicArray<T>::push(const T& value)
{
    // If the allocated space is not enough, allocate a bigger memory
    if (m_size >= m_capacity)
    {
        // Double Capacity: Geomtric growth gives fewer reallocations & amortized O(1) insertion
        // 1st push: 1 memory block
        // 2nd push: 2 memory blocks
        // 3rdnd push: 4 memory blocks etc.
        std::size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        resize(newCapacity);
    }

    // Add value to next memory block
    data[m_size++] = value;
}

template <typename T> T DynamicArray<T>::pop()
{
    if (m_size == 0)
    {
        std::out_of_range("Array is empty");
    }

    // Store last element
    T value = data[m_size - 1];

    // Reduce size
    --m_size;

    return value;
}

template <typename T> void DynamicArray<T>::clear()
{
    m_size = 0;
}

template <typename T> void DynamicArray<T>::print() const
{
    std::cout << "[ ";
    for (std::size_t i = 0; i < m_size; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

template <typename T> void DynamicArray<T>::printMemLayout() const
{
    for (std::size_t i = 0; i < m_size; ++i)
    {
        std::cout << "Index: " << i << " Address: " << &data[i] << std::endl;
    }
}

template <typename T> T& DynamicArray<T>::operator[](std::size_t index)
{
    return data[index];
}

template <typename T> const T& DynamicArray<T>::operator[](std::size_t index) const
{
    return data[index];
}

template <typename T> T& DynamicArray<T>::at(std::size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return data[index];
}

template <typename T> const T& DynamicArray<T>::at(std::size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return data[index];
}

template <typename T> typename DynamicArray<T>::iterator DynamicArray<T>::begin()
{
    return data;
}

template <typename T> typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const
{
    return data;
}

template <typename T> typename DynamicArray<T>::iterator DynamicArray<T>::end()
{
    return data + m_size;
}

template <typename T> typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const
{
    return data + m_size;
}

template <typename T> DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    m_size     = other.m_size;
    m_capacity = other.m_capacity;

    data = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; ++i)
    {
        data[i] = other.data[i];
    }
}

template <typename T> DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    delete[] data;

    m_size     = other.m_size;
    m_capacity = other.m_capacity;

    data = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; ++i)
    {
        data[i] = other.data[i];
    }

    return *this;
}