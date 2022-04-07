// write this program to accept the x & y coordinates of a point
//By Ear Choung Pheng

#include <iostream> //so we use input and output

using namespace std;// so we can use cout and cin

int main() {
    float x, y; // define x and y variable

    cout << "This is a program to accept the x & y coordinates of a point.\n"; // print message
    cout << "Enter x: "; // get x input from user
    cin >> x; // save to x
    cout << "Enter y: "; // get y input from user
    cin >> y; // save to y
    cout << "(" << x << ", " << y << ") "; // print message

    if(x > 0 && y > 0) { // checking if x and y is bigger than 0
        cout << "is in Quadrant 1."; // print message
    }
    else if(x < 0 && y > 0) { // checking if x is smaller than 0 and y is bigger than 0
        cout << "is in Quadrant 2."; // print message
    }
    else if(x < 0 && y < 0) { // checking if x and y is smaller than 0
        cout << "is in Quadrant 3."; // print message
    }
    else if(x > 0 && y < 0) { // checking if x is bigger than 0 and y is smaller than 0
        cout << "is in Quadrant 4."; // print message
    }
    else if(x == 0 && y == 0) { // checking if x and y is 0
        cout << "is on the x-axis and y-axis."; // print message
    }
    else if(x == 0) { // checking if x is 0
        cout << "is on the y-axis."; // print message
    }
    else if(y == 0) { // checking if y is 0
        cout << "is on the x-axis."; // print message
    }
    return 0; // end program
}