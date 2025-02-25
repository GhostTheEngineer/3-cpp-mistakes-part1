/******************************************************************************
 * Project: 3 C++ Misconceptions
 * File: item1_using_std_namespace_is_fine.cpp
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.0.1
 * Author: Ghost
 * Created On: 02-24-2025
 * Last Modified: 02-24-2025
 *****************************************************************************/

#include <iostream>
#include <cmath>  // Brings in `std::max()`
#include <iterator> // FIX - Brings in std::distance() (not from cmath)
#include <vector>

/*
    Misconception #1: `using namespace std;` is always fine
    False: It pollutes the global namespace and can cause naming conflicts in large projects.
    Correct: Instead of `using namespace std;`, explicitly reference `std::cout`, `std::endl`, etc.

    NOTE: this code is meant to fail to demonstrate the ambiguity it will create from the cause of 
    the name pollution `using namespace std;`

        If you wish to fix, just simply remove the `using namespace std;` and include the namespace 
        qualifier to parts of code that matter like cout, distance(), max().

*/

using namespace std;  // Pollutes the namespace!

double distance = 2.5;  // Name conflicts with `std::distance()`
int max = 25;  // Name conflicts with `std::max()`

int main() {
    cout << "Misconception: \"`using namespace std;` is always fine\"\n";

    cout << "  Distance: " << distance << "\n"; // IDE knows the error!

    int x1 = 1, x2 = 10;
    vector<int> vec = {1, 2, 3, 4, 5}; // NEW - meant to be used with distance function below

    // ERROR: Compiler doesn't know if `distance` is a variable or function!
    cout << "  Distance: " << distance(vec.begin(), vec.end()) << "\n";  // FIX - using correct function from correct lib

    // You could rename `distance` to `dist` to fix it...
    // But what about `max`?
    cout << "  Max: " << max << "\n";

    // ERROR: `max` is now a variable, so we can't use `std::max(x1, x2)`
    cout << "  Max value: " << max(x1, x2) << "\n";  

    // Sometimes renaming variables isn’t possible, and `using namespace std;` causes conflicts like this.

    return 0;
}
