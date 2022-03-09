//Write this program to accept Celsius and convert it to Kelvin and Fahrenheit
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs

using namespace std; //use standard name space

int main() { // main function
    float celsius; // Define celsius variable

    cout << "Enter degree in Celsius: "; // Get input from user
    cin >> celsius; // Save input to 'celsius'

    cout << "The value of " << celsius << " degrees C in K is: " << celsius + 273.15 << endl; // Print result of C to K
    cout << "The value of " << celsius << " degrees C in F is: " << celsius*1.8 + 32;
    return 0; // Print result of C to F
} // Close the main function