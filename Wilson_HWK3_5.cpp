/*
 * Zoe Wilson
 * January 26, 2016
 * Homework 3.5
 *
 */

#include <iostream>
#include <string>
 
/*
 * Calculates the hat size.
 * @param weight
 * @param height
 * @return hat size
 */
double get_hat_size(float weight, float height) {
    return ((double) weight / (double) height) * 2.9;
}

/*
 * Calculates the jacket size.
 * @param height
 * @param weight
 * @param age
 * @return jacket size
 */
double get_jacket_size(float height, float weight, float age) {
    if (age >= 40) {
        return ((height * weight) / 288) + (((age / 10) - 3) * .125);
    } else {
        return ((height * weight) / 288);
    }
}

/*
 * Calculates the waist size.
 * @param weight
 * @param age
 * @return waist size
 */
double get_waist_size(float weight, float age) {
    if (age >= 30) {
        return (weight / 5.7 ) + (((age / 2) - 14) * .1);
    } else {
        return (weight / 5.7);
      }
}

/*
 * If the string is 'y', return false, else return true.
 * @param answer
 * @return false if 'y', else true
 */
bool done(std::string answer) {
    return (answer.compare("y") == 0) ? false : true;
}


int main() {

    float height = 0;
    float weight = 0;
    float age = 0;

    double hat_size;
    double jacket_size;
    double waist_size;

    std::string answer = "";

    while(true) {

        //Gets measurements from the user
        std::cout << "Enter your height in inches, your weight in pounds, and your age:" << std::endl;
        std::cin >> height >> weight >> age;

        // Calculate hat size
        hat_size = get_hat_size(weight, height);
        // Calculate jacket size
        jacket_size = get_jacket_size(height, weight, age);
        //Calculate waist size
        waist_size = get_waist_size(weight, age);
        
        // Displaying results
        std::cout << std::endl
                  << "Hat size: " << hat_size << std::endl
                  << "Jacket size: " << jacket_size << std::endl
                  << "Waist size: " << waist_size << std::endl << std::endl;

        // Prompting user to do it again
        std::cout << "Would you like to find your clothing sizes again? y/n" << std::endl;
        std::cin >> answer;
        std::cout << std::endl;
        if (done(answer)) {
            break;
        }

    }

    return 0;
}
