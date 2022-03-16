//Write this program to accept the number and check wether it is a prime number or composite number.
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs

using namespace std; // use standard name space

int main() { // main function
    int num; // define number variable
    bool isPrime = true; // define isPrime variable and set it to True
    
    cout << "Enter a positive number: "; // get input from user
    cin >> num; // save user input to 'num'

    if(!cin) { // check if cin failed to get an interger from user
        cout << "Invalid input!"; // print error
    }

    if(num == 0|| num == 1) { // if number is 0 or 1
        cout << "Number " << num << " is not a prime nor composite number."; // print message 
        isPrime = false;
    }

    for(int i=2; i<=num/2; i++) { // start of 'for loop'
        if(num % i == 0) { // if num % i = 0 then number is dividible
            if(isPrime) { // isPrime is true
                isPrime = false; // set isPrime to false
                cout << "Number " << num << " is a composite number." << endl; // print message
                cout << "The factors of " << num << " are: "; // print message
            }

            if(!isPrime) {// if isPrime is false
                cout << i << " "; // print the factor
            }
        }
    }

    if(isPrime) { // if number is prime
        cout << "Number " << num << " is a prime number."; // print message 
    }

} // closing main function