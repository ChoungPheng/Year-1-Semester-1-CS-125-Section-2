//Write this program to accept read a list of exam scores (ranging from 0 to 100) and display the total number of grades
//Written by Ear Choung Pheng

#include <iostream> //To include inputs and outputs
#include <string> // Include so we can use string
#include <sstream> // Include so we can use stringstream

using namespace std; // use standard name space

int main() { // main function

    // define variables
    string givenList, score; 
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    float totalScores = 0;

    cout << "Enter your scores: "; // get input from user
    getline(cin, givenList); // save input from user to 'givenList'
    stringstream scoresList(givenList); // turning 'givenList' into stringsteam

    while(getline(scoresList, score, ' ')) { // while loop if we can getline from scoresList

        // this is to handle syntax or anything other than integers
        try { // try turning score into integer
            stoi(score); // turn string to integer
        }
        catch(...) { // catch error if string cannot turn into integer then stop grading
            break; // stop while loop
        }

        // grade the scores
        if(stoi(score) > 100) { //if score is bigger than 100
            cout << "The value '" << score << "' is out of range." << endl; // print error
        }
        else if(stoi(score) >= 90) { //if score is bigger than or equal to 90
            totalScores += stoi(score);
            gradeA++; // add 1 to grade
        }
        else if(stoi(score) >= 80) { //if score is bigger than or equal to 80
            totalScores += stoi(score);
            gradeB++; // add 1 to grade
        }
        else if(stoi(score) >= 70) { //if score is bigger than or equal to 70
            totalScores += stoi(score);
            gradeC++; // add 1 to grade
        } 
        else if(stoi(score) >= 60) { //if score is bigger than or equal to 60
            totalScores += stoi(score);
            gradeD++; // add 1 to grade
        }
        else if(stoi(score) >= 0){ //if score is bigger than or equal to 0
            totalScores += stoi(score);
            gradeF++; // add 1 to grade
        }
        else { // if score is negative then stop grading
            break; // stop while loop
        }
    }

    //print the number of grades
    cout << "Number of A's " << gradeA << endl;
    cout << "Number of B's " << gradeB << endl;
    cout << "Number of C's " << gradeC << endl;
    cout << "Number of D's " << gradeD << endl;
    cout << "Number of F's " << gradeF << endl;
    cout << "The total number of scores are: " << gradeA + gradeB + gradeC + gradeD + gradeF << endl;

    return 0; // stops the program
}