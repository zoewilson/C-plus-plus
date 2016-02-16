/*
 * Zoe Wilson
 * February 15, 2016
 * Homework 6.3
 */

#include <iostream>

class Point {

  public:

    // Sets user input equal to private variables
    void set(int _x, int _y) {
        x = _x;
        y = _y;
    }

    // Moves coordinates along x and y axis 
    void move(int _x, int _y) {
        x += _x;
        y += _y;
    }

    // Rotates the coordinates clockwise 90 degrees
    void rotate() {
        if (x > 0) {
            if (y > 0) {
                x *= -1;
            } else {
                y *= -1;
            }
        } else {
            if (y > 0) {
                y *= -1;
            } else {
                x *= -1;
            }
        }
    }

    // Returns 'x' constant to the user
    int retrieve_x() const {
        return x;
    }

    // Returns 'y' constant to the user
    int retrieve_y() const {
        return y;
    }

  private:
    int x;
    int y;
};

    //Finds out if user would like to run again
    bool quit() {
        std::string answer = "";

        std::cout << "Do you want to enteer another point in the plane? (y/n) " << std::endl;

        while (true) {
            std::cin >> answer;
            if(answer.compare("y") == 0) {
                return false;
            } else if (answer.compare("n") == 0) {
                return true;
            } else {
                std::cout << "Invalid answer. Must be 'y' or 'n'." << std::endl;
            }
        }
    }

int main() {
    int x;
    int y;
    int a;
    int b;
    Point* p = new Point();

    while (true) {
        // Get coordinates from the user
        std::cout << "Enter in your point: " << std::endl;    
        std::cin >> x >> y;

        // Set x and y
        p->set(x,y);

        // Get amount wanted to move x and y axis
        std::cout << "Enter in the amount you would like to move x and y: " << std::endl;
        std::cin >> a >> b;

        // Move method
        p->move(a,b);
        std::cout << "The new coordinates after move() is: " << p->retrieve_x() << " " << p->retrieve_y() << std::endl;

        // Rotate Coordinates
        p->rotate();
        std::cout << "The new coordinates after rotate() is: " << p->retrieve_x() << " " << p->retrieve_y() << std::endl;

        // Ask user to run again
        if (quit()) {
            break;
        }
      }
}
        
    
