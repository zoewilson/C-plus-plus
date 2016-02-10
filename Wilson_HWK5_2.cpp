/*
 *Zoe Wilson
 *February 9, 2016
 *Homework 5.2
 */

#include <iostream>
#include <vector>
#include <sstream>


std::vector<char> delete_repeats(char a[], int& count){
    std::vector<char> seen;
    seen.push_back(a[0]); // We know we want the first element

    for (int i = 1; i < count; i++) {
        bool found = false;
        for (int j = 0; j < seen.size(); j++) {
            if (a[i] == seen[j]) {
                found = true;
            }
        }
        if (!found) {
            seen.push_back(a[i]);
        }
    }
    count = seen.size();
    return seen;
}

int main() {
    char array[] = {'a', 'b', 'c', 'd', 'a', 'x', 'x', 'h'};
    int count = 8;
    std::vector<char> new_array = delete_repeats(array, count);
    
    std::cout << "The original array was: {'a', 'b', 'c', 'd', 'a', 'x', 'x', 'h'} with a count of 8." 
              << std::endl;
    std::cout << "The new array is: ";     
    
    for (int i = 0; i < new_array.size(); i++) {
        std::cout << new_array[i];
    }  
    std::cout << " with a count of " << count << "." << std::endl;

}
