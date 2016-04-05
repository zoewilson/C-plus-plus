/*
 * Zoe Wilson
 * April 5, 2016
 * Average number of words
 */

#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    const int SIZE = 250;
    char array[SIZE];
    int lines = 0;
    int words = 0;
    int i = 0;

    // Input file object.
    std::ifstream in;

    // Open file.
    in.open("text.txt");

    while(in) {

        // Reads file.
        in.getline(array, SIZE, '\n');
        i = 0;

        // Counts the lines.
        if(in.gcount()) {
            lines++;
            while(array[i]) {

                // Checks if uppercase, lowercase, or decimal digit.
                if(isalnum(array[i])) {
                    words++;
                    i++;
                    while(isalnum(array[i])) {
                        i++;
                    }
                } else 
                    i++;
            }
         }
    }

    // Close file.
    in.close();

    // Print Results.
    std::cout << "Average number of words per sentence: " << (double) words/(double) lines << std::endl;

    return 0;
 }
