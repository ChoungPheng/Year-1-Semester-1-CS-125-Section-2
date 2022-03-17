#include <iostream> //To include inputs and outputs
#include <string> // Include so we can use string
#include <sstream> // Include so we can use stringstream

using namespace std; // use standard name space

int main() { // main function

    // define variables
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    float score = 0, totalScores = 0;

    cout << "Enter number: "; // get input from user

    while(true) { // start while loop
        cin >> score; // save user input to 'score'

        if(cin) { // if cin successful
            // grade the scores
            if(score > 100) { //if score is bigger than 100
                cout << "The value '" << score << "' is out of range." << endl; // print error 
                break; // stop while loop
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
}