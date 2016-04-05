/*
 * Zoe Wilson
 * April 5, 2016
 * Number Lines
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>

int main() {
    // File object.
    std::ifstream file;

    // Name of file.
    std::string name;

    // Holds a line of input.
    std::string input_line;

    //Line counter.
    int lines = 0;

    // Line number display.
    int line_num = 1;

    // Gets the file name.
    std::cout << "Enter the file name: " << std::endl;
    std::getline(std::cin, name);

    // Open the file.
    file.open(name.c_str());

    // Test for any errors.
    if (!file) {
        std::cout << "Error opening " << name << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read and display each line number.
    std::getline(file, input_line, '\n');
    while (!file.fail()) {
        std::cout << std::setw(3) << std::right << line_num 
                  << ":" << input_line << std::endl;

        // Increment to the next line.
        line_num++;

        // Update counter.
        lines++;

        // Pause if line exceeds 24.
        if (lines == 24) {
            std::cout << "Press ENTER to continue..." << std::endl;
            std::cin.get();
            lines = 0;
        }

        // Get a line from the file.
        std::getline(file, input_line, '\n');
    }

    // Close the file.
    file.close();
    return 0;
}

