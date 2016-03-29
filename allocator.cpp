/*
 * Zoe Wilson
 * March 29, 2016
 * Array Allocator
 */

#include <iostream>

/*
 * Inputs the user to enter in the size of the array.
 * @return size of array.
 */
int get_size(int size) {
    std::cout << "Enter in the size of the array" << std::endl;
    std::cin >> size;
    return size;
}

 /*
 * Caller must keep track of the pointer.
 * The Caller is responsible to free up the allocated memory.
 * @param size of the array.
 * @return a pointer to the array
 */
int* allocate_array(int size) {
    int* array = new int(size);

    for(int i = 0; i < size; i++) {
        std::cout << "Enter num " << i + 1 << std::endl;
        std::cin >> array[i];
    }

    return array;
}

int main() {
    int size = 0;
    int* array;
    
    // Get size of the array
    size = get_size(size);
    // Allocate array
    array = allocate_array(size);

    // Fills array
    for(int i = 0; i < size; i++) {
        std::cout << array[i] << std::endl;
    }
}
