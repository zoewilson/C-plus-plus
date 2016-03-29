/*
 * Midterm Practice
 */

#include <iostream> 

double get_widget_num(double p, double weight){
    return ((weight - p) / 12.5);
}

int main() {
    double pallet;
    double total_weight;

    std::cout << "How much does the pallet weigh? " << std::endl;
    std::cin >> pallet;

    std::cout << "How much does the whole thing weigh? " << std::endl;
    std::cin >> total_weight;


    std::cout << "The number of widgets on the pallet is: " << get_widget_num(pallet, total_weight) << std::endl;
} 
