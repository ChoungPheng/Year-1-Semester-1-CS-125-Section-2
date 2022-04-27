//Write this program to continuously accept numbers until the user key in -1 (a sentinel value). Display the highest, and lowest numbers and display the average of all the values entered by the user.
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs
#include <algorithm> //To include sort

using namespace std; // use standard name space

int main() { 
    //! Declare variables
    float tempList[100];
    int size = 0;
    bool valid = false;

    //! Accept list of numbers from user
    while(!valid) {
        cout << "Enter your list of numbers: ";

        for(int i=0;i<100;i++) {
            float tempNumber; //? declare a temporary variable

            cin >> tempNumber;
            if(!cin) { //? check if it is a letter/symbol
                cout << "Invalid Input.\n";
                size = 0;
                cin.clear();
                cin.ignore(100, '\n');
                break;
            }
            else if(tempNumber < -1){ //? check if number is negative
                cout << "Please number of positive number.\n";
                size = 0;
                break;
            }
            else if(tempNumber >= 0) { //? Adding numbers to temporary list
                tempList[i] = tempNumber;
                size += 1; //? calculating the size of the entered list
            }
            else { //? Detecting sentinel value "-1"
                valid = true;
                break;
            }
        }
    }

    float *list = new float[size]; //? Create new array with new list size

    for(int i=0;i<size;i++) {
        list[i] = tempList[i]; //? add numbers to new list
    }   

    sort(list, list + size, less<float>()); //? Sort the list

    //! Display Highest Number
    cout << "Highest Number is: " << list[size-1] << endl;

    //! Display Lowest Number
    cout << "Highest Number is: " << list[0] << endl;

    //! Display the average of all the values

    float sum = 0; //? new variable for sum of all values

    for(int i=0;i<size;i++) {
        sum += list[i]; //? calculating the sum
    }
    cout << "Average: " << sum/size << endl; //? Display the sum

    system("pause");
    return 0;
}