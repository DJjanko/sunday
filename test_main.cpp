#include <iostream>
#include "main.h" // Include the header file containing the declaration of sestej
#include <fstream>

int main() {
    int flag1 = 0;
    int flag2 = 0;
    // Test Case 1
    int result1 = sestej(1, 2);
    if (result1 == 3) {
        flag1 = 1;
    }

    // Test Case 2
    int result2 = sestej(3, 5);
    if (result2 == 8) {
        flag2 = 1;
    }

    std::ofstream result_file("result.txt");
    if (result_file.is_open()) {
        if (flag1 && flag2) {
            result_file << "SUCCESS" << std::endl;
        } else {
            result_file << "FAILED" << std::endl;
        }
        result_file.close();
    } else {
        // Unable to open file, print error message
        std::cerr << "Error: Unable to open result file." << std::endl;
        return 1;
    }

    return 0;
}
