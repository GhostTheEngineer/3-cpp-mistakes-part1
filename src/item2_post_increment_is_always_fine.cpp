/******************************************************************************
 * Project: 3 C++ Misconceptions
 * File: item2_post_increment_is_always_fine.cpp
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
#include <vector>

/*
    Misconception #2: `i++` and `++i` are always the same.
    False: Compilers optimize `i++` for primitive types (`int`), but NOT for iterators or objects.
    Correct: Use `++i` for iterators and objects to avoid unnecessary copies.
*/

//_______________________________________ 
class DebugIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int*;
    using reference = int&;

private:
    pointer ptr;

public:
    static int copy_count;  // Tracks number of copies

    DebugIterator(pointer p) : ptr(p) {}

    // Copy constructor (tracks when copies are made)
    DebugIterator(const DebugIterator& other) : ptr(other.ptr) {
        ++copy_count;
    }

    // Pre-increment (++it)
    DebugIterator& operator++() {
        ++ptr;
        return *this;
    }

    // Post-increment (it++)
    DebugIterator operator++(int) {
        DebugIterator temp = *this;  // Creates a temporary (extra copy)
        ++ptr;
        return temp;
    }

    reference operator*() { return *ptr; }
    bool operator!=(const DebugIterator& other) const { return ptr != other.ptr; }
};

int DebugIterator::copy_count = 0;
//_______________________________________


int main() {
    std::cout << "Misconception: \"`i++` and `++i` are always the same\"\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // BAD CODE
    std::cout << "  Using it++ (Post-Increment, BAD for iterators):\n";
    for (DebugIterator it = DebugIterator(vec.data()); it != DebugIterator(vec.data() + vec.size()); it++) {
        // Do something..
    }
    std::cout << "    Copies created: " << DebugIterator::copy_count << "\n";
    std::cout << "    Total Size: " << (sizeof(DebugIterator) * DebugIterator::copy_count) << " bytes\n";

    DebugIterator::copy_count = 0;  // Reset copy count

    // GOOD CODE
    std::cout << "\n  Using ++it (Pre-Increment, BETTER for iterators):\n";
    for (DebugIterator it = DebugIterator(vec.data()); it != DebugIterator(vec.data() + vec.size()); ++it) {
        // Do something..
    }
    std::cout << "    Copies created: " << DebugIterator::copy_count << "\n";
    std::cout << "    Total Size: " << (sizeof(DebugIterator) * DebugIterator::copy_count) << " bytes\n";

    return 0;
}
