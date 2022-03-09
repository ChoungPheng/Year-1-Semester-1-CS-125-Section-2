//Write this program to accept name and age. if age is even then print name 10 times. if name is odd then print name 5 times.
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs
#include <string.h> // Include so we can use string

using namespace std; //use standard name space

int main() { // main function
    #define MAX_NAME 50 // define max number of letters for the 'name ' variable
    char name[MAX_NAME]; //define name variable with max length of 50 letters
    int age; // define age variable

    cout << "Enter your name: "; // get input from user
    cin.getline(name, MAX_NAME); // save user input to 'name'

    cout << "Enter your age: "; // get input from user
    cin >> age; // save user input to 'age'

    if(age % 2) { // age % 2 == 1 which mean 'age' is an odd number
        int count = 0; // define count = 0 so we can count
        while (count < 5) { // while loop until count is equal or greater 5
            cout << name << endl; // print the name
            count++; // add 1 to 'count'
        }
    }
    else { // age % 2 == 0 which mean 'age' is an even number
        int count = 0; // define count = 0 so we can count
        while (count < 10) { // while loop until count is equal or greater 10
            cout << name << endl; // print the name
            count++; // add 1 to 'count'
        }
    }
} // closing main function

