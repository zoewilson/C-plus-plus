/*
 * Zoe Wilson
 * February 23, 2016
 * Homework 7.3
 */

#include <iostream>
#include <string>

/*
 * Increments specific digits
 */
class Counter {

  public:

    /* Constructor */
    Counter(int max) {
        max_limit = max;
        count = 0;
        penny, dime, dollar, ten = 0;
    }

    /* Sets the counter number to 0 */
    void reset() {
        penny, dime, dollar, ten = 0; 
    }

    /* Increments one's digit */
    void incr1() {
        penny += 1;
        if (penny >= 10) {
            incr10();
            penny = 0;
        }
    }
    
    /* Increments ten's digit */
    void incr10() {
        dime += 1;
        if( dime >= 10 ) {
            incr100();
            dime = 0;
        }
    }

    /* Increments hundred's digit */
    void incr100() {
        dollar += 1;
        if( dollar >= 10 ) {
            incr1000();
            dollar= 0;
        }
    }

    /* Increments thousand's digit */
    void incr1000() {
        ten += 1;
    }

    /* Prints out message depending on overflow occurance. */
    void check_overflow() {
        if (overflow()) {
          std::cout << "Overflow" << std::endl;
        } else {
          std::cout << "No overflow. Total amount: " << count << std::endl;
        }
    }

    /* Checks if count is greater than max. */
    bool overflow() {
        count = penny + (dime * 10) + (dollar * 100) + (ten * 1000);
        return count > max_limit;
    }

  private: 

        /* Default constructor: not to be used */
        Counter() {} 

        /* Member variables */
        int penny;
        int dime;
        int dollar;
        int ten;
        int count;
        int max_limit; 
};
 
  void print_info() {
        std::cout << "In order to increment each digit use 'a' for pennies, followed by a digit 1 "
                  << "to 9; 's' for dimes, followed by " 
                  << std::endl
                  << "a digit 1 to 9; 'd' for a dollar, followed by a digit 1 to 9; 'f' for tens, "
                  << "followed by a digit 1 to 9. " 
                  << std::endl 
                  << "Make sure to press the enter key after every letter followed by a digit. " 
                  << std::endl 
                  << "Enter 'o' in order to request overflow. " 
                  << std::endl;
  }

    /* Gets input from the user. */
    void get_input(Counter* c) {
        std::string method;
        int digit;

        std::cin >> method >> digit;

        // Checks if entered in 'a'.
        // If so, run incr1() method equivalent to digit number.
        if (method == "a") {
            for (int i = 0; i < digit; i++) {
                c->incr1();
            }
            c->check_overflow();
        } 

        // Checks if entered in 's'.
        // If so, run incr10() method equivalent to digit number.
        if (method == "s") {
            for (int i = 0; i < digit; i++) {
                c->incr10();
            }
            c->check_overflow();
        } 
    
        // Checks if entered in 'd'.
        // If so, run incr100() method equivalent to digit number.
        if (method == "d") {
            for (int i = 0; i < digit; i++) {
                c->incr100();
            }
            c->check_overflow();
        } 

        // Checks if entered in 'f'.
        // If so, run incr1000() method equivalent to digit number.
        if (method == "f") {
            for (int i = 0; i < digit; i++) {
                c->incr1000();
            }
            c->check_overflow();
        } 

        // Tells user overflow if they enter 'o'.
        if(method == "o") {
            c->overflow();
        }
    }
  
  /* Ask user if they would like to enter again */
  bool quit() {
    std::string answer;
    std::cout << "Do you want to enter again? (y/n) ";

    while(true) {
        std::cin >> answer;
        if (answer == "y" || answer == "Y") {
            return false;
        } else if (answer == "n" || answer == "N") {
            return true;
        } else {
            std::cout << "Invalid input: please enter 'y' or 'n'. ";
        }
    }
  }

int main() {
    Counter* c = new Counter(9999);
    print_info();
    while (true) {
        get_input(c);

        // Run again
        if (quit()) {
            break;
        }
    }
}
