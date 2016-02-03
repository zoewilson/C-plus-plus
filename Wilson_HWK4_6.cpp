/*
 * Zoe Wilson 
 * February 2, 2016
 * Homework 4.6
 */

#include <iostream>
#include <math.h>
#include <cmath>
 
/* 
 * Contains Imperial Measurments for feet and inches
 */
struct Imperial {
    double feet;
    double inches;
};

/* 
 * Contains Metric Measurments for meters and centimeters
 */
struct Metric {
    double meters;
    double centimeters;
};

/*
* Find out what conversion the user wants
* 1 = Imperial to Metric
* 2 = Metric to Imperial
*/
bool is_imperial_to_metric() {
    int type;
    std::cout << "Enter '1' for Metric to Imperial or '2' for Imperial to Metric. " << std::endl;

    while (true) {
        std::cin >> type; 
        if(type == 1) {
            return false;
        } else if (type == 2) {
            return true;
        } else {
            std::cout << "Invalid answer. Must be a '1' or '2'." << std::endl;
        }
     }
    return type;
}

// Gets input from the user
Metric get_metric_input() {
    Metric m;
    std::cout << "Enter in the meters of your measurement, then the centimeters." << std::endl;
    std::cin >> m.meters >> m.centimeters;
    return m;
}

// Gets input from the user
Imperial get_imperial_input() {
    Imperial i;
    std::cout << "Enter in the feet of your measurement, then the inches." << std::endl;
    std::cin >> i.feet >> i.inches;
    return i;
}

/*
 * Converts Imperial to Metric
 */
Metric convert_to_metric(double feet, double inches) {
    Metric m;
    inches += (feet * 12 );
    m.centimeters = inches * 2.54;
    m.meters = m.centimeters / 10.0;
    m.centimeters = std::fmod(m.meters, 1.0);
    return m;
}

/*
 * Converts Metric to Imperial
 */
Imperial convert_to_imperial(double meters, double centimeters) {
    Imperial i;
    centimeters += (meters * 100);
    i.inches = centimeters / 2.54;
    i.feet = i.inches / 12;
    i.inches = std::fmod(i.feet, 1.0);
    return i;
}


// Prints conversion to the user
void print_metric(double meters, double centimeters) {
    std::cout << (int) meters << " meters and " << centimeters << " centimeters " << std::endl;
}

// Prints conversion to the user
void print_imperial(double feet, double inches) {
    std::cout << (int) feet << " feet and " << inches << " inches " << std::endl;
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

void imperial_to_metric() {
    // Get users input
    Imperial i = get_imperial_input();

    // Convert to metric system
    Metric m = convert_to_metric(i.feet, i.inches);
        
    // Print results
    print_metric(m.meters, m.centimeters);
}

void metric_to_imperial() {
    // Get users input
    Metric m = get_metric_input();

    // Convert to metric system
    Imperial i = convert_to_imperial(m.meters, m.centimeters);
        
    // Print results
    print_imperial(i.feet, i.inches);
}


int main() {
    while (true) {
        if (is_imperial_to_metric()) {
            imperial_to_metric();
        } else {  
            metric_to_imperial();
        }
        // Ask to play again
        if (quit()) {
            break;
        }
    }
    return 0;
}
