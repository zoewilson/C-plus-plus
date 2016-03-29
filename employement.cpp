/*
 * Zoe Wilson
 * March 5, 2016
 * Employee problem #2
 */
 
#include <iostream>

/*
 * Returns number of employees within the company
 */
int get_number_of_employees() {
    int number_of_employees = 0;

    do {
        // Input for number of employees.
        std::cout << "Enter the number of employees in your company. " << std::endl;
        std::cin >> number_of_employees;
        // Must enter a value of one or more.
    
        if (number_of_employees < 1) {
            std::cout << "Must enter a value of one or more. " << std::endl;
        }
    } while (number_of_employees < 1);

    return number_of_employees;
}

/*
 * Returns the total number of missed days.
 */
int get_total_missed_days(int num_of_employees) {
    int missed_days = 0.0;
    int total_missed_days = 0.0;

    
    for (int i = 1; i <= num_of_employees; i++) {
        do {
            std::cout << "How many days did employee " << i << " miss this year? " << std::endl;
            std::cin >> missed_days;
            // Missed days cannot be negative.
            if (missed_days < 0) {
                std::cout << "Missed days cannot be negative. Please re-enter: " << std::endl;
            }
        } while(missed_days < 0);
        // Adds missed days for every employee into total.
        total_missed_days += missed_days;
    }
    return total_missed_days;
}

/*
 * Returns the average amount of days employees miss per year.
 */
double get_avg(int num_of_employees, int total_missed_days) {
    return (double) total_missed_days / (double) num_of_employees;
}

int main() {
    // Number of employees in the company.
    int e;
    // Total number of missed days.
    int m;
    // Average days missed by employees per year
    double avg;

    // Get employee number.
    e = get_number_of_employees();
    // Get total number of missed days.
    m = get_total_missed_days(e);
    // Get average days missed.
    avg = get_avg(e,m);

    // Print results.
    std::cout << "The average amount of days missed by your employees per year is: " << avg 
              << " days " << std::endl;
}
    



