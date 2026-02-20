#include <iostream>

#include "section3/static_array/static_array.h"

int main()
{
    std::cout << "--- Static Array ---\n\n";

    StaticArray<int, 5> arr;

    // Size
    std::cout << "Size: " << arr.size() << "\n";
    std::cout << std::endl;

    // Content
    std::cout << "Content: \n";
    arr.print();
    std::cout << std::endl;

    // Fill
    std::cout << "Fill: \n";
    arr.fill(1);
    arr.print();
    std::cout << std::endl;

    // ================
    // MemoryModel
    // ================
    std::cout << "Base Address: \n";
    std::cout << arr.begin() << std::endl;
    // Memory Layout
    std::cout << "Memory Layout: \n";
    arr.printMemLayout();
    std::cout << std::endl;

    // Modify elements
    // Compiler selects the non-const version: T& operator[](std::size_t index);
    std::cout << "Modify elements: \n";
    arr[0] = 3;
    arr[1] = 6;
    arr[2] = 13;
    arr.print();
    std::cout << std::endl;

    // Access elements
    // Compiler selects const version: const T& operator[](std::size_t index) const;
    std::cout << "Access elements: \n";
    int x = arr[1];
    std::cout << x << " " << arr[2] << std::endl;
    std::cout << std::endl;

    // Access elements with bound check
    std::cout << "Access elements with bound check: \n";
    try
    {
        std::cout << arr.at(20) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    std::cout << std::endl;

    // Loops
    // Iterator Loop
    std::cout << "Iterator Loop: \n";
    for (StaticArray<int, 5>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}