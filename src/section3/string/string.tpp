#include "string.h"

#include <cstring>
#include <stdexcept>

String::String() : size(0), capacity(1)
{
    data    = new char[capacity];
    data[0] = '\0';
}

String::String(const char* str)
{
    size     = std::strlen(str);
    capacity = size + 1;
    data     = new char[capacity];
    std::strcpy(data, str);
}

String::String(const String& other)
{
    size     = other.size;
    capacity = other.capacity;
    data     = new char[capacity];
    std::strcpy(data, other.data);
}

String::~String()
{
    delete[] data;
}

void String::resize(int newCapacity)
{
    char* newData = new char[newCapacity];
    std::strcpy(newData, data);
    delete[] data;
    data     = newData;
    capacity = newCapacity;
}

void String::push(char c)
{
    if (size + 1 >= capacity)
        resize(capacity * 2);

    data[size++] = c;
    data[size]   = '\0';
}

char String::pop()
{
    if (size == 0)
        std::out_of_range("String is empty, can not pop");

    char removedChar = data[size - 1];

    size--;
    data[size] = '\0';

    return removedChar;
}

void String::clear()
{
    size       = 0;
    data[size] = '\0';
}

char& String::operator[](int index)
{
    return data[index];
}

const char& String::operator[](int index) const
{
    return data[index];
}

const char* String::c_str() const
{
    return data;
}

int String::length() const
{
    return size;
}

bool String::is_empty() const
{
    return size == 0;
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        size     = other.size;
        capacity = other.capacity;
        delete[] data;
        data = new char[capacity];
        std::strcpy(data, other.data);
    }

    return *this;
}

String String::operator+(const String& other) const
{
    String result;

    result.resize(size + other.size + 1);
    std::strcpy(result.data, data);
    std::strcat(result.data, other.data);
    result.size = size + other.size;

    return result;
}

bool String::operator==(const String& other) const
{
    return std::strcmp(data, other.data) == 0;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.data;

    return os;
}