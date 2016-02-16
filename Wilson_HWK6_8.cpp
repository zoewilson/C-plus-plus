/*
 * Zoe Wilson
 * February 15, 2016
 * Homework 6.8
 */

#include <iostream>

class Money {
  public:
    /*
     * Constructor.
     *
     */
    Money(int d, int c) {
        dollars = d;
        cents = c;
    }

    /* Destructor. */
    ~Money(){}

    void set(int d, int c) {
        dollars = d;
        cents = c;
    }

    /* Returns dollars */ 
    int get_dollars() {
        return dollars;
    }

    /* Returns cents */ 
    int get_cents() {
        return cents;
    }

    /* 
     * Returns total monetary value provided by constructor
     */
    double monetary_amount() {
        return (double) dollars + ((double) cents / 100.0);
    }

  private:
    /*
     * Default constructor.
     * Not to be used.
     */
    Money() {}

    /* The dollars. */
    int dollars;

    /* The cents. */
    int cents;
};

int main() {
    /* Objects of Money class */
    Money* a = new Money(10,58); 
    Money* b = new Money(4,21);

    /* Prints results */
    std::cout << "Amount 1: " << a->monetary_amount() << std::endl << "Amount 2: " << b->monetary_amount() << std::endl;
}
