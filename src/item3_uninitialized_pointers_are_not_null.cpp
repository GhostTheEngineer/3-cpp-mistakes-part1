/******************************************************************************
 * Project: 3 C++ Misconceptions
 * File: item3_uninitialized_pointers_are_not_null.cpp
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.0.0
 * Author: Ghost
 * Created On: 02-24-2025
 * Last Modified: 02-24-2025
 *****************************************************************************/


#include <iostream>

/*
    Misconception #3: Uninitialized Pointers are Always Null
    False: Uninitialized pointers hold garbage addresses, NOT nullptr.
    Correct: Always initialize pointers explicitly to `nullptr` or allocate memory before using.
*/

int main() {
    std::cout << "Misconception: \"Uninitialized Pointers are Always Null\"\n";

    int* ptr;  // Uninitialized pointer (DANGLING!)
    int* safePtr = nullptr;  // Correctly initialized

    std::cout << "  Uninitialized pointer: " << ptr << " (Garbage address!)\n";
    std::cout << "  Initialized pointer: " << safePtr << " (Safe: nullptr)\n";

    // Dereferencing an uninitialized pointer causes undefined behavior
    // std::cout << *ptr << "\n";  // BAD: May cause segmentation fault!

    ptr = new int{2};
    std::cout << "  Pointer(ptr) " << ptr << " now points to an integer with a value of " << *ptr << "\n";
    delete ptr;
    std::cout << "  Deleted Data at Pointer(ptr) " << ptr << " - currently dangling..\n";
    // std::cout << *ptr << "\n";  // BAD: This data has been freed and attempting to access may cause segmentation fault!

    ptr = nullptr; // CORRECT: ensure pointers that do not point to a valid memory are set to nullptr!
    std::cout << "  Pointer(ptr) " << ptr << " now set to `nullptr`\n";

    // SAFETY CHECK - always check if pointer is valid - NOTE: this will not protect against dangling pointer only checks for non-nullptr
    std::cout << "  Checking if Pointer(ptr) " << ptr << " is `nullptr`\n";
    if (ptr) {
        std::cout << *ptr << "\n";
    }
    else {
        std::cout << "  Pointer is null.\n";
    }

    return 0;
}
