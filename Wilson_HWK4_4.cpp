/*
 * Zoe Wilson 
 * February 2, 2016
 * Homework 4.4
 */

#include <iostream>
#include <math.h>
#include <cmath>
 
/* 
 * Contains Imperial Measurments for feet and inches
 */
struct Imperial {
    int feet;
    int inches;
};

/* 
 * Contains Metric Measurments for meters and centimeters
 */
struct Metric {
    double meters;
    double centimeters;
};

// Gets input from the user
Imperial get_input() {
    Imperial i;
    std::cout << "Enter in the feet of your measurement, then the inches." << std::endl;
    std::cin >> i.feet >> i.inches;
    return i;
}

/*
 * Converts Imperial to Metric
 */
Metric convert_to_metric(int feet, int inches) {
    Metric m;
    inches += (feet * 12 );
    m.centimeters = ((double) inches) * 2.54;
    m.meters = m.centimeters / 10.0;
    m.centimeters = std::fmod(m.meters, 1.0);
    return m;
}

// Prints conversion to the user
void print_metric(double meters, double centimeters) {
    std::cout << (int) meters << " meters and " << centimeters << " centimeters " << std::endl;

}

// Finds out if user would like to run again
bool quit() {
    std::string answer = "";

    std::cout << "Do you want to enter another measurement? (y/n) " << std::endl;

    while (true) {
        std::cin >> answer;
        if(answer.compare("y") == 0) {
            return false;
        } else if (answer.compare("n") == 0) {
            return true;
        } else {
            std::cout << "Invalid answer. Must be a 'y' or 'n'." << std::endl;
        }
     }
}

int main() {
    while (true) {
        // Get users input
        Imperial i = get_input();

        // Convert to metric system
        Metric m = convert_to_metric(i.feet, i.inches);
        
        // Print results
        print_metric(m.meters, m.centimeters);

        // Ask to play again
        if (quit()) {
            break;
        }
    }
    return 0;
}
