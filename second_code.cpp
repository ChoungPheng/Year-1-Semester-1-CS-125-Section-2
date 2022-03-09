//Write this program to accept the radius of a cirlce and print the area and circumference
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs

using namespace std; // Use standard name space

int main() { // Main function
    #define PI 3.14159 // Define PI
    float radius; // Define radius variable

    cout << "Enter radius: "; // Get input from user
    cin >> radius; // Save input from user to 'radius'

    cout << "The area of the circle is: " << PI * radius*radius << endl; // Print area of the circle
    cout << "The circumference of the circle is: " << 2 * PI * radius; // Print circumference of the circle
} // Close the main function