// Copyright 2026 Vladislav
#include <stdexcept>
#include "lib_algorithms/Algorithms.h"

float division(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Input Error: can't divide by zero!");
    }
    return static_cast<float>(a) / b;
}

// bool check_breckets(std::string expression) {
//     StackOnMass<char>  stack = StackOnMass();
//     for (char i : expression) {
//
//     }
// }
