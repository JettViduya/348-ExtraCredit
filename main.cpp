//Author: Jett Viduya, KUID: 3115988, Date: 11/27/24, Lab: Extra credit lab, Purpose: Write a C++ code that extracts double precision nums from strings.
#include <iostream>
#include <iomanip>
#include <string>

// Function to extract a valid double from a string
double extractNumeric(const std::string& str) {
    int i = 0;
    bool decimalPoint = false;  // To track if we encounter a decimal point
    double result = 0.0;
    bool negative = false;

    // Handle potential negative sign
    if (str[i] == '-') {
        negative = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Process the string character by character
    for (; i < str.size(); ++i) {
        char ch = str[i];

        // If the character is a digit, add it to the result
        if (ch >= '0' && ch <= '9') {
            result = result * 10 + (ch - '0');
        }
        // If the character is a decimal point, set the flag
        else if (ch == '.' && !decimalPoint) {
            decimalPoint = true;
        }
        // Invalid character encountered
        else {
            return -999999.99;
        }
    }

    // Apply the decimal point if present
    if (decimalPoint) {
        double divisor = 10;
        i = str.size() - 1;
        while (i >= 0 && str[i] != '.') {
            result /= divisor;
            divisor *= 10;
            --i;
        }
    }

    return negative ? -result : result;
}

// Main was provided via instructions on Canvas
int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string (or 'END' to quit): ";
        std::cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            std::cout << "The input is: " << std::fixed << std::setprecision(4) << number << std::endl;
        } else {
            std::cout << "The input is invalid" << std::endl;
        }
    }

    return 0;
}


