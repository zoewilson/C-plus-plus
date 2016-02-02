/*
 * Zoe Wilson
 * January 26, 2016
 * Homework 3.7
 *
 */

#include <iostream>
#include <math.h>

/*
 * v = wind speed in m/sec
 * t = temperature in Celsius
 * W = wind chill index
 * @return wind chill index
 */
double get_wind_chill_factor (double v, double t) {
    return (33 - (((10 * (sqrt(v)) - v + 10.5) * (33 - t)) / 23.1));
} 
    
int main() {
    double v = 0;
    double t = 0;
    
    double W = 0;
    
    //get values from user
    std::cout << "Enter a wind speed and a temperature. " << std::endl;
    std::cin >> v >> t;

    //gets wind chill
    W = get_wind_chill_factor(v, t);
    std::cout << "Wind chill index: " << W << std::endl;

return 0;

}
