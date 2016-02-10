/*
 * Zoe Wilson
 * February 9, 2016
 * Homework 5.5
 */

#include <iostream>
#include <vector>
#include <sstream>

const int MAX_SIZE = 20;


struct IntegerOverflow {
    int size;
    IntegerOverflow(int s) {
        size = s;
    }
};

struct Arrays {
    std::string a;
    std::string b;
};

// Get input from the user
Arrays get_arrays() {

    Arrays arrays;

    std::cout << "Enter two arrays: ";
    std::cin >> arrays.a >> arrays.b;

    if (arrays.a.length() > MAX_SIZE || arrays.b.length() > MAX_SIZE) { 
       throw IntegerOverflow(MAX_SIZE);
    }

    return arrays; 
}

// Load strings into arrays
std::vector<int> load_arrays(std::string a, std::string b) {

    // Insert first string into int array 
    std::vector<int> array_one;
    for (int i = a.size() - 1; i >= 0; i--) {
        int val;
        std::istringstream(a.substr(i,1)) >> val;
        array_one.push_back(val);
    }

    // Insert second string into int array
    std::vector<int> array_two;
    for (int i = b.size() - 1; i >= 0; i--) {
        int val;
        std::istringstream(b.substr(i,1)) >> val;
        array_two.push_back(val);
    }
    
    // Load up smaller array with 0's
    if (array_one.size() < array_two.size()) {
        for (int i = 0; i < (array_two.size() - array_one.size()); i++)
            array_one.push_back(0);
    } else if (array_one.size() > array_two.size()) {
        for (int i = 0; i < (array_one.size() - array_two.size()); i++)
            array_two.push_back(0);
    }

    // Add two arrays together
    std::vector<int> final_array;
    int carry_over = 0;
    int value = 0;
    for(int i = 0; (i <= array_one.size()) && (i <= array_two.size()); i++) {
        value = array_one[i] + array_two[i];
        final_array.push_back((value + carry_over) % 10);
        carry_over = (value >= 10) ? 1 : 0;
    }
    
    return final_array;
}

void print_array(std::vector<int> final_array) {

    // Print the final array
    std::cout << "final array: ";
    bool first = true;
    int val;
    for (int i = final_array.size(); i >= 0; i--) {
        val = final_array[i];
        if (first && (val == 0)) {
            continue;
        }
        std::cout << val;
        first = false;
    }
    std::cout << std::endl;
}

// Ask user if they would like to enter again
bool quit() {

    std::string answer;
    std::cout << "Do you want go again? (Y/n) ";

    while (true) {
        std::cin >> answer;
        if (answer == "y" || answer == "Y") {
            return false;
        } else if (answer == "n" || answer == "N") {
            return true;
        } else {
            std::cout << "Invalid input: please answer 'yes' or 'no'. ";
        }
    }
}

int main() {

    // Get final array
    while (true) {
        Arrays arrays;

        //Catches throw in get_arrays 
        try {
            arrays = get_arrays();
        } catch (IntegerOverflow& e){
            std::cerr << "Error: Cannot exceed array size: " << e.size << std::endl;
            continue;
        }
        
        std::vector<int> final_array = load_arrays(arrays.a, arrays.b);
        print_array(final_array);
        
        // Run again
        if (quit()) {
            break;
        }
    }
}
