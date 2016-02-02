/*
 * Zoe Wilson
 * February 2, 2016
 * Homework 4.1
 */

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>


struct TimeInformation {
    int hour;
    std::string minutes;
    char period;
};

int get_hour(int &hour) {
    if (hour >= 12) {
        return hour %= 12;
    } else if (hour == 0) {
        return 12;
    }
    return hour;
}

char get_period(int &hour) {
    char period = '0';
    if (hour < 12) {
        return 'A';
    }
    return 'P';
}

TimeInformation get_time(std::string time, int index) {

    TimeInformation time_info;

    // Get string hour and string minutes
    std::string string_hour = time.substr(0, index);
    time_info.minutes = time.substr(index);

    // Convert string to integer
    int hour = 0;
    std::stringstream ss(string_hour);
    if (!(ss >> hour)) {
        std::cerr << "ERROR: failed to convert string " << string_hour << " to integer.";
    } 

    // Get converted hour and get AM or PM
    time_info.hour = get_hour(hour);
    time_info.period = get_period(hour);

    return time_info;
}

std::string get_input() {
    std::string time = "";
    std::cout << "Enter the time: ";
    std::cin >> time;
    return time;
}


void print_time(int hour, std::string minutes, char period) {
    std::cout << hour << minutes << " " << period << std::endl;
}

bool quit() {
    std::string answer = "";

    std::cout << "Do you want to enter another time? (y/n) " << std::endl;

    while (true) {
        std::cin >> answer;
        if (answer.compare("y") == 0) {
            return false;
        } else if (answer.compare("n") == 0) {
            return true;
        } else {
            std::cout << "Invalid answer. Must be 'y' or 'n'." << std::endl;
        }
    }
}


int main() {

    while (true) {
        // Get user input
        std::string time = get_input();

        // Find the index for 
        int index = 0;
        try {
            index = time.find(":");
        } catch (std::exception& e) {
            std::cout << "Invalid input! Must be in the format XX:XX or X:XX" << std::endl;
            continue;
        }
        
        // Get hour and minute data
        TimeInformation time_info = get_time(time, index);

        // Print time
        print_time(time_info.hour, time_info.minutes, time_info.period);

        // Ask to play again
        if (quit()) {
            break;
        }
    }

    return 0;
}
