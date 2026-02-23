#include <iostream>

#include "section3/string/string.h"

int main()
{
    std::cout << "--- String ---\n\n";

    // Default Constructor
    String s1;
    std::cout << "String: " << s1 << " Length: " << s1.length() << std::endl;

    // C-String Constructor
    String s2("Hello");
    std::cout << "String: " << s2 << " Length: " << s2.length() << std::endl;

    // Copy Constructor
    String s3 = s2;
    std::cout << "String: " << s3 << " Length: " << s3.length() << std::endl;

    // Copy Assignment
    String s4;
    s4 = s2;
    std::cout << "String: " << s4 << " Length: " << s4.length() << std::endl;

    // Push
    s2.push(' ');
    s2.push('w');
    s2.push('o');
    s2.push('r');
    s2.push('l');
    s2.push('d');
    std::cout << "String: " << s2 << " Length: " << s2.length() << std::endl;

    // Pop
    s2.pop();
    std::cout << "String: " << s2 << " Length: " << s2.length() << std::endl;

    // Modify
    s2[0] = 'h';
    std::cout << "String: " << s2 << " Length: " << s2.length() << std::endl;

    // Concatination
    String s5(" !!!");
    String s6 = s2 + s5;
    std::cout << "String: " << s6 << " Length: " << s6.length() << std::endl;

    // Equality check
    String a("test");
    String b("Test");
    String c("test");
    std::cout << "a == b ? " << (a == b ? "true" : "false") << std::endl;
    std::cout << "a == c ? " << (a == c ? "true" : "false") << std::endl;

    // Clear
    s2.clear();
    std::cout << "Is S2 empty? " << (s2.is_empty() ? "yes" : "no") << std::endl;

    // c_str
    String      s7("Custom String");
    const char* raw = s7.c_str();
    std::cout << "c_str() raw: " << raw << std::endl;

    return 0;
}