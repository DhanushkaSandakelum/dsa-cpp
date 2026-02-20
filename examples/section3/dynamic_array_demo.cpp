#include <iostream>

#include "section3/dynamic_array/dynamic_array.h"

int main()
{
    std::cout << "--- Dynamic Array ---\n\n";

    DynamicArray<int> arr;

    std::cout << "Initial Size: " << arr.size() << "\n";
    std::cout << "Initial Capacity: " << arr.capacity() << "\n";
    std::cout << "Is Empty?: " << arr.is_empty() << "\n";
    std::cout << std::endl;

    // Push
    std::cout << "Push: \n";
    for (std::size_t i = 1; i <= 5; ++i)
    {
        int x = i * 10;
        arr.push(x);
        std::cout << "Element pushed: " << x << " Size: " << arr.size()
                  << " Capacity: " << arr.capacity() << " Content: ";
        arr.print();
    }
    std::cout << std::endl;

    // Memory model
    std::cout << "Memory Layout: \n";
    arr.printMemLayout();
    std::cout << std::endl;

    // Direct Access
    std::cout << "Direct Access: \n";
    // -- Modify elements
    std::cout << "-- Modify elements: \n";
    arr[1] = 88;
    arr.print();
    std::cout << std::endl;

    // -- Read elements
    std::cout << "-- Read elements: \n";
    int x = arr[1];
    std::cout << x << " " << arr[2] << std::endl;
    std::cout << std::endl;

    // Safe Access
    std::cout << "Safe Access: \n";
    // -- Modify elements
    std::cout << "-- Modify elements: \n";
    try
    {
        arr.at(2) = 77;
        arr.print();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    std::cout << std::endl;

    // -- Read elements
    std::cout << "-- Read elements: \n";
    try
    {
        int y = arr.at(20);
        std::cout << y << " " << arr.at(3) << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    std::cout << std::endl;

    // Loops
    std::cout << "Loops: \n";
    // -- Range-based Loop
    std::cout << "-- Range-based Loop: \n";
    for (auto const& value : arr)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // -- Iterator Loop
    std::cout << "-- Iterator Loop: \n";
    for (DynamicArray<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Copy Constructor
    std::cout << "\nCopy Constructor: \n";
    DynamicArray<int> arr2 = arr;
    arr2.print();
    std::cout << std::endl;

    // Copy Assignment
    std::cout << "Copy Assignment: \n";
    DynamicArray<int> arr3;
    arr3 = arr;
    arr3.print();
    std::cout << std::endl;

    return 0;
}