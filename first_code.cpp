#include <iostream>

using namespace std;

int main() {
    //Define the variables
    int x,y,z;
    //Take Inputs from User and save to the variables
    cout << "Enter First Number: ";
    cin>>x;
    cout << "Enter Second Number: ";
    cin>>y;
    cout << "Enter Third Number: ";
    cin>>z; 
    //Display Results
    cout << "The sum of " << x << "," << y << "," << z << " is " << x+y+z << ".\n";
    cout << "The average of " << x << "," << y << "," << z << " is " << (x+y+z)/3 << ".\n";
    cout << "The product of " << x << "," << y << "," << z << " is " << x*y*z << ".";
    return 0;
}