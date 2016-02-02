/*
 * Zoe Wilson
 * January 26, 2016
 * Homework 3.8
 *
 */

#include <iostream>
#include <sstream>

/* Represents zero through nine */
const std::string SINGLE_DIGITS[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

/* Represents the one's column */
const std::string ONES[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

/* Represents the ten's column */
const std::string TENS[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};

/* Represents the teens */
const std::string TEENS[] = { "Ten", "Eleven", "Tweleve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

/*
 * Returns the written-out English representation of the integer value.
 * @param number
 * @return string representation of number
 */
std::string getValue(int number) {

    std::ostringstream string;

    // For numbers 20-99
    if (number >= 20) {

        // If number is multiple of 10 (e.g., 20, 30, 40)
        if (number % 10 == 0) {
            string << TENS[number / 10];
        } 
        
        // If number is not a multiple of 10 (e.g., 21, 34, 69)
        else {
            string << TENS[number / 10] << "-" << ONES[number % 10];
        }
    } 
    
    // For numbers 10-19
    else if (number >= 10) {
        string << TEENS[number - 10];
    } 
    
    // For numbers 0-9
    else {
        string << SINGLE_DIGITS[number];
    }

    return string.str();
}

/*
 * Prints the stanza with the proper value written out in English.
 * @param count - the number of bottles
 */
void printStanza(int count) {
    std::cout << getValue(count) << " bottles of beer on the wall, " << std::endl 
              << getValue(count) << " bottles of beer, " << std::endl 
              << "Take one down, pass it around, " << std::endl
              << getValue(count - 1) << " bottles of beer on the wall." << std::endl << std::endl;
}

/*
 * Runs through "99 Bottles of Beer on the Wall".
 */
int main() {
    
    for (int i = 99; i > 0; i--) {
        printStanza(i);
    }
    
    return 0;
}
