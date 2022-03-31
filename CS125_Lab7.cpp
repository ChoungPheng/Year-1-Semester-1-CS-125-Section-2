//Write this program to accept read a list of exam scores (ranging from 0 to 100) and display the total number of grades
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs
#include <unistd.h>
#include <string.h>
#include <sstream>

using namespace std; // use standard name space

bool exitProgram = false;

bool isNumber(const string& string){
    for(char const &c : string) {
        if(!isdigit(c)) return false;
    }
    return true;
}

void displayMenu() {
    cout << endl  << "================================================================================" << endl;
    cout << "MAIN MENU: Select Laboratory Activity" << endl;
    cout << "       [1] On Arithmetic Operators and Keyboard Input" << endl;
    cout << "       [2] On Arithmetic Operators" << endl;
    cout << "       [3] On Number of Time Name is Printed, Depends on Age" << endl;
    cout << "       [4] On Accept the Current Temperature and Display Messages Based on Range" << endl;
    cout << "       [5] On Prime and Composite Numbers" << endl;
    cout << "       [6] On Grading a List of Scores" << endl;
    cout << "       [7] On Switch" << endl;
    cout << "       [X] Exit" << endl;
}

void ActivityOne() {
    cout << "===========================================" << endl;
    cout << "On Arithmetic Operators and Keyboard Input:" << endl;
    cout << "===========================================" << endl;
    //Define the variables
    string num1,num2,num3;
    int x,y,z;
    //Take Inputs from User and save to the variables
    while(true) {
        cout << "Enter First Number: ";
        getline(cin, num1);
        bool valid = false;

        try {
            

            int x = stoi(num1);

            if(to_string(x).length() == num1.length()) {
                valid = true;
            }
            else {
                valid = false;
            }
        }
        catch(...) {
            valid = false;
        }

        if(valid) {
            stringstream ss;
            ss << num1;
            ss >> x;
            break;
        }
        else {
            cout << "Invalid input! Please enter a number!" << endl;
            continue;
        }
    }
    while(true) {
        cout << "Enter Second Number: ";
        getline(cin, num2);
        if(isNumber(num2)) {
            stringstream ss;
            ss << num2;
            ss >> y;
            break;
        }
        else {
            cout << "Invalid input! Please enter a number!" << endl;
            continue;
        }
    }
    while(true) {
        cout << "Enter Third Number: ";
        getline(cin, num3);
        if(isNumber(num3)) {
            stringstream ss;
            ss << num3;
            ss >> z;
            break;
        }
        else {
            cout << "Invalid input! Please enter a number!" << endl;
            continue;
        }
    }
    
    //Display Results
    cout << "The sum of " << x << "," << y << "," << z << " is " << x+y+z << ".\n";
    cout << "The average of " << x << "," << y << "," << z << " is " << (x+y+z)/3 << ".\n";
    cout << "The product of " << x << "," << y << "," << z << " is " << x*y*z << ".\n";
    sleep(1.2);
    displayMenu();
}

void RadiusProgram() {
    cout << "======================" << endl;
    cout << "Circumference and Area" << endl;
    cout << "======================" << endl;
    #define PI 3.14159 // Define PI
    float radius; // Define radius variable

    cout << "Enter radius: "; // Get input from user
    cin >> radius; // Save input from user to 'radius'
    cin.ignore(100, '\n');

    cout << "The area of the circle is: " << PI * radius*radius << endl; // Print area of the circle
    cout << "The circumference of the circle is: " << 2 * PI * radius << endl; // Print circumference of the circle
}
void TemperatureProgram() {
    cout << "======================" << endl;
    cout << "Temperature Conversion" << endl;
    cout << "======================" << endl;
    float celsius; // Define celsius variable

    while(true) {
        cout << "Enter degree in Celsius: "; // Get input from user
        if(cin >> celsius) {
            cout << "The value of " << celsius << " degrees C in K is: " << celsius + 273.15 << endl; // Print result of C to K
            cout << "The value of " << celsius << " degrees C in F is: " << celsius*1.8 + 32 << endl;
            break;
        }
        else {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid Input!" << endl;
        }
    }
    cin.ignore(100, '\n');
}

void ActivityTwo() {
    cout << "=================================" << endl;
    cout << "SELECT PROGRAMS:" << endl;
    cout << "       [1] Circumference and Area" << endl;
    cout << "       [2] Temperature Conversion" << endl;
    cout << "       [B] Go Back" << endl;

    bool hasError = false;
    
    while(true) {
        string choiceString;
        char choice;

        cout << "Your Choice: ";
        getline(cin, choiceString);

        if(choiceString.size() < 2 && choiceString.size() > 0){

            choice = choiceString[0];
            switch(choice){
                case '1':
                    RadiusProgram();
                    break;
                case '2':
                    TemperatureProgram();
                    break;
                case 'b':
                    break;
                case 'B':
                    break;
                default: 
                    hasError = true;
                    break;
            }
        }
        else {
            hasError = true;
        }

        if(hasError) {
            cout << "Please input a valid option." << endl;
            hasError = false;
            continue;
        }
        else {
            hasError = false;
            sleep(1);
            displayMenu();
            break;
        }
    }
}

void ActivityThree() {
    cout << "==============================================" << endl;
    cout << "Number of Time Name is Printed, Depends on Age" << endl;
    cout << "==============================================" << endl;
    #define MAX_NAME 50 // define max number of letters for the 'name ' variable
    char name[MAX_NAME]; //define name variable with max length of 50 letters
    int age; // define age variable

    cout << "Enter your name: "; // get input from user
    cin.getline(name, MAX_NAME); // save user input to 'name'

    cout << "Enter your age: "; // get input from user
    cin >> age; // save user input to 'age'
    cin.ignore(100, '\n');

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
    sleep(1.2);
    displayMenu();
}

void ActivityFour() {
    cout << "==================================================================" << endl;
    cout << "Accept the Current Temperature and Display Messages Based on Range" << endl;
    cout << "==================================================================" << endl;
    int temp; //  define temperature variable

    cout << "Enter temperature: "; // get input from user
    cin >> temp; // save user input to 'temp'
    cin.ignore(100, '\n');

    if(!cin) { // check if cin failed to get interger from user
        cout << "Input invalid!" << endl; // print error
    } 
    else { 
        if(temp < 20) { // if temperature is below 20
            cout << "Cool breeze in the air!" << endl; // print message
        }
        else if(temp <= 25) { // if temperature range between 20-25
            cout << "Always keep your cool!" << endl; // print message
        }
        else if(temp <= 31) { // if temperature range between 26-31
            cout << "Keep a sunblock handy!" << endl; // print message
        }
        else if(temp <= 40) { // if temperature range between 32-40
            cout << "Stay cool and safe!" << endl; // print message
        }
        else if(temp <= 54) { // if temperature range between 41-54
            cout << "Stay hydrated!" << endl; // print message
        }
        else { // if temperature is out of range
            cout << "Value out of range!" << endl; // print message
        }
    }
    sleep(1.2);
    displayMenu();
}

void ActivityFive() {
    cout << "===========================" << endl;
    cout << "Prime and Composite Numbers" << endl;
    cout << "===========================" << endl;
    int num; // define number variable
    bool isPrime = true; // define isPrime variable and set it to True
    
    cout << "Enter a positive number: "; // get input from user
    cin >> num; // save user input to 'num'
    cin.ignore(100, '\n');

    if(!cin) { // check if cin failed to get an interger from user
        cout << "Invalid input!" << endl; // print error
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
    cout << endl;
    sleep(1.2);
    displayMenu();
}

void ActivitySix() {
    cout << "========================" << endl;
    cout << "Grading a List of Scores" << endl;
    cout << "========================" << endl;
    // define variables
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    float score = 0, totalScores = 0;

    cout << "Enter scores: "; // get input from user

    while(true) { // start while loop
        cin >> score; // save user input to 'score'

        if(cin) { // if cin successful
            // grade the scores
            if(score > 100) { //if score is bigger than 100
                cout << "The value '" << score << "' is out of range." << endl; // print error
            }
            else if(score >= 90) { //if score is bigger than or equal to 90
                totalScores += score;
                gradeA++; // add 1 to grade
            }
            else if(score >= 80) { //if score is bigger than or equal to 80
                totalScores += score;
                gradeB++; // add 1 to grade
            }
            else if(score >= 70) { //if score is bigger than or equal to 70
                totalScores += score;
                gradeC++; // add 1 to grade
            } 
            else if(score >= 60) { //if score is bigger than or equal to 60
                totalScores += score;
                gradeD++; // add 1 to grade
            }
            else if(score >= 0){ //if score is bigger than or equal to 0
                totalScores += score;
                gradeF++; // add 1 to grade
            }
            else { // if score is negative then stop grading
                break; // stop while loop
            }
        }
        else { // if cin failed
            break; // stop while loop
        }
    }
    
    //print the number of grades
    cout << "Number of A's " << gradeA << endl;
    cout << "Number of B's " << gradeB << endl;
    cout << "Number of C's " << gradeC << endl;
    cout << "Number of D's " << gradeD << endl;
    cout << "Number of F's " << gradeF << endl;
    // print total number of scores
    cout << "The total number of scores are: " << gradeA + gradeB + gradeC + gradeD + gradeF << endl;
    cin.ignore(100, '\n');
    sleep(1.2);
    displayMenu();
}

void DayOfTheWeek() {
    cout << "===============" << endl;
    cout << "Day of the Week" << endl;
    cout << "===============" << endl;
    int day;
    /* Input day number from user */
    cout << "Enter number: ";
    cin >> day;
    cin.ignore(100, '\n');

    switch(day)
    {
        case 1:
            cout << "It's Monday!";
            break;
        case 2: 
            cout << "It's Tuesday!";
            break;
        case 3: 
            cout << "It's Wednesday!";
            break;
        case 4: 
            cout << "It's Thursday!";
            break;
        case 5: 
            cout << "It's Friday!";
            break;
        case 6: 
            cout << "It's Saturday!";
            break;
        case 7: 
            cout << "It's Sunday!";
            break;
        default:
            cout << "Invalid Input!";
            break;
    }
    cout << endl;
    sleep(1.2);
    displayMenu();
}
void EvenOrOdd() {
    cout << "==================" << endl;
    cout << "Even or Odd Number" << endl;
    cout << "==================" << endl;
    
    int num;

    cout << "Enter number: ";
    cin >> num;
    cin.ignore(100, '\n');

    switch(num % 2)
    {
        // If n%2 == 0
        case 0: 
            cout << "Number " << num << " is an even number.";
            break;

        // Else if n%2 == 1
        case 1: 
            cout << "Number " << num << " is an odd number.";
            break;
    }

    cout << endl;
    sleep(1.2);
    displayMenu();
}

void ActivitySeven() {
    char choice;
    cout << "=============================" << endl;
    cout << "SELECT PROGRAMS:" << endl;
    cout << "       [1] Day of the Week" << endl;
    cout << "       [2] Even or Odd Number" << endl;
    cout << "       [B] Go Back" << endl;
    cout << "Your Choice: ";
    cin >> choice;
    cin.ignore(100, '\n');

    switch(choice){
        case '1':
            DayOfTheWeek();
            break;
        case '2':
            EvenOrOdd();
            break;
        case 'b':
            break;
        case 'B':
            break;
    }
}

int main() { // main function
    displayMenu();
    while (!exitProgram) {
        string choiceString;
        char choice;

        cout << "Your Choice: ";
        getline(cin, choiceString);

        if(choiceString.size() < 2 && choiceString.size() > 0){

            choice = choiceString[0];

            switch(choice){
                case '1':
                    ActivityOne();
                    break;
                case '2':
                    ActivityTwo();
                    break;
                case '3':
                    ActivityThree();
                    break;
                case '4':
                    ActivityFour();
                    break;
                case '5':
                    ActivityFive();
                    break;
                case '6':
                    ActivitySix();
                    break;
                case '7':
                    ActivitySeven();
                    break;
                case 'x':
                    cout << "Exiting Program...";
                    exitProgram = true;
                    break;
                case 'X':
                    cout << "Exiting Program...";
                    exitProgram = true;
                    break;
                default:
                    cout << "Please input a valid option." << endl;
                    break;
            }
        }
        else {
            cout << "Please input a valid option." << endl;
        }
    }

    return 0;
}