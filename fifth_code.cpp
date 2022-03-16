//Write this program to accept the current temperature and display messages based on range
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs

using namespace std; // use standard name space

int main() { // main function
    int temp; //  define temperature variable

    cout << "Enter temperature: "; // get input from user
    cin >> temp; // save user input to 'temp'

    if(!cin) { // check if cin failed to get interger from user
        cout << "Input invalid!"; // print error
    } 
    else { 
        if(temp < 20) { // if temperature is below 20
            cout << "Cool breeze in the air!"; // print message
        }
        else if(temp <= 25) { // if temperature range between 20-25
            cout << "Always keep your cool!"; // print message
        }
        else if(temp <= 31) { // if temperature range between 26-31
            cout << "Keep a sunblock handy!"; // print message
        }
        else if(temp <= 40) { // if temperature range between 32-40
            cout << "Stay cool and safe!"; // print message
        }
        else if(temp <= 54) { // if temperature range between 41-54
            cout << "Stay hydrated!"; // print message
        }
        else { // if temperature is out of range
            cout << "Value out of range!"; // print message
        }
    }
} // closing main function