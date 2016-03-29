/*
 * Zoe Wilson
 * March 3, 2016
 * Hotel problem #1
 */

#include <iostream>
#include <math.h>

int main() {
    int floors = 0;
    double total_rooms = 0;
    double total_occupied = 0;

    // Input top floor.
    std::cout << "What is the top floor of your hotel?" << std::endl;
    std::cin >> floors;

    double rooms = 0;
    double occupied = 0;
    // Gets number of rooms and number of occupied rooms for every floor.
    for (int i = 1; i <= floors; i++) {
        // Skips floor 13.
        if(i == 13){
            continue;
        }

        // Input for total number of rooms.
        std::cout << "How many rooms total on the " << i << " floor?" << std::endl;
        std::cin >> rooms;

        // Input for number of occupied rooms.
        std::cout << "How many rooms are occupied on the " << i << " floor?" << std::endl;
        std::cin >> occupied;
        
        // Calculates total number of rooms and occupied rooms.
        total_rooms += rooms;
        total_occupied += occupied;
    }

    // Printing results
    std::cout << "The total number of rooms in the hotel are: " << total_rooms << std::endl
              << "The total number of occupied rooms are: " << total_occupied << std::endl
              << "The total number of unoccupied rooms are: " << (total_rooms - total_occupied)
              << std::endl
              << "The percentage of occupied rooms is: " << ((total_occupied / total_rooms)* 100)
              << "%" << std::endl;
} 

