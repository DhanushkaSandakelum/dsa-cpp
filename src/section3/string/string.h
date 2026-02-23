#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
  private:
    char* data;
    int   size;
    int   capacity;

    void resize(int newCapacity);

  public:
    String();
    String(const char* str);
    String(const String& other); // copy constructor

    ~String();

    // Modifiers
    void push(char c);
    char pop();
    void clear();

    // Direct Access
    char&       operator[](int index);
    const char& operator[](int index) const;

    // Utilities
    const char* c_str() const;
    int         length() const;
    bool        is_empty() const;

    // Operators
    String& operator=(const String& other); // copy assignment
    String  operator+(const String& other) const;
    bool    operator==(const String& other) const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

#include "string.tpp"

#endif