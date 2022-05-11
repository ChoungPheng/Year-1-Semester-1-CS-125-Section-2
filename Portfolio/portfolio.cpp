#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <utility>
#include <Windows.h>

using namespace std;

bool isNumber(const string& string){ //? Check for number in string
    for(char const &c : string) {
        if(!isdigit(c)) return false;
    }
    return true;
}

void AddScoresToUser(int scores) {
    string currentUsername;
    string currentPassword;
    string currentScore;

    //! Reading username
    fstream currentUserFile;
    currentUserFile.open("currentUser.txt", ios::in);
    if(currentUserFile.is_open()) {
        int count = 0;
        string line;
        while(getline(currentUserFile, line)) {
            if(count == 0) {
                currentUsername = line;
            }
            if(count == 1) {
                currentScore = line;
            }
            count++;
        }
        currentUserFile.close();
    }

    //! Overwriting current user info
    fstream newCurrentUserFile;
    newCurrentUserFile.open("currentUser.txt", ios::out);
    if(newCurrentUserFile.is_open()) {
        newCurrentUserFile << currentUsername << endl;
        newCurrentUserFile << stoi(currentScore) + scores;
        newCurrentUserFile.close();
    }

    //! Reading user info
    fstream user;
    user.open("./accounts/" + currentUsername +".txt", ios::in);
    if(user.is_open()){
        string line;
        int count = 0;
        while(getline(user, line)) { //? Storing the user info to an Array
            if(count == 1) {
                currentPassword = line;
            }
            count++;
        }
        user.close();
    }

    //! Overwriting user info
    fstream newUser;
    newUser.open("./accounts/" + currentUsername +".txt", ios::out);
    if(newUser.is_open()){
        newUser << currentUsername << endl;
        newUser << currentPassword << endl;
        newUser << stoi(currentScore) + scores;
        newUser.close();
    }
}

void GuessTheCorrectNumber() {
    cout << "====================================\n";
    cout << "Guess the correct number ranging from 1 to 10.\n";

    srand((unsigned int)time(NULL)); //? Add seed to random
    int correctNumber = rand() % 10 + 1;
    
    bool hasWon = false;
    int chances = 5;
    while(!hasWon) {
        string guess;
        cout << "Chances: " << chances << endl;
        cout << "Your Guess: ";
        getline(cin, guess);
        if(isNumber(guess) && guess != "") { //? Validate
            //! Check if answer is correct
            if(stoi(guess) != correctNumber && chances == 1) {
                chances--;
            }
            else if(stoi(guess) > correctNumber) {
                cout << "Lower!\n";
                chances--;
            }
            else if(stoi(guess) < correctNumber) {
                cout << "Higher!\n";
                chances--;
            }
            else {
                hasWon = true;
                cout << "You won! " << guess << " was the correct number! ";
            }
        }
        else {
            cout << "Please input a number!\n";
            chances--;
        }
        if(chances == 0) {
            cout << "You lost! The correct number was " << correctNumber << ".\n";
            break;
        }
    }
    if(hasWon) {
        //! Scoring
        int score = 1;
        if(chances >= 4) {
            score = 3;
        }
        else if(chances >= 2) {
            score = 2;
        }
        cout << "Scores + " << score << endl; 
        AddScoresToUser(score);
    }
    system("pause");
}

void GuessTheWord() {
    cout << "====================================\n";
    string wordsList[50] = {"Airplane", "Ears", "Piano", "Angry", "Elephant", "Pinch", "Baby", "Fish", "Reach", "Ball", "Flick", "Remote", "Baseball", "Football", "Roll", "Basketball", "Fork", "Sad", "Bounce", "Giggle", "Scissors", "Cat", "Golf", "Skip", "Chicken", "Guitar", "Sneeze", "Chimpanzee", "Hammer", "Spin", "Clap", "Happy", "Spoon", "Cough", "Horns", "Stomp", "Cry", "Joke", "Stop", "Dog", "Mime", "Tail", "Drink", "Penguin", "Toothbrush", "Drums", "Phone", "Wiggle", "Duck", "Photographer"};
    srand((unsigned int)time(NULL)); //? seed for random
    string guessWord = wordsList[rand() % 50];

    int charToRemoved = guessWord.size()/3;
    int chances = charToRemoved + 2;
    int scoresToGive = 1;
    //! Scoring
    if(guessWord.size() > 6) { 
        scoresToGive = 3;
    }
    else if(guessWord.size() > 4) {
        scoresToGive = 2;
    }
    
    //! Generate a word with missing letters
    char* characters = new char[guessWord.size()];
    characters[guessWord.size()] = '\0';

    for(int i=0; i<guessWord.size(); i++) {
        characters[i] = guessWord[i];
    }

    for(int i=0; i<charToRemoved; i++) {
        int random = rand() % guessWord.size();
        characters[random] = '#';
    }
    cout << "Find the missing letters of: " << string(characters) << endl;
    bool hasWon = false;
    while(!hasWon) {
        string answer;
        cout << "chances: " << chances << endl;
        cout << "Type in the full word: ";
        getline(cin, answer);
        //! Check answers
        if(answer == guessWord) {
            hasWon = true;
            cout << "You've won! The word '" << answer << "' was correct! Scores + " << scoresToGive << endl;
            break;
        }
        else {
            chances--;
        }
        if(chances == 0) {
            cout << "You've lost! The correct word was '" << guessWord << "'.\n";
            break;
        }
    }
    if(hasWon) {
        AddScoresToUser(scoresToGive);
    }
    system("pause");
}

void Scoreboard() {
    cout << "====================================\n";
    cout << "            Scoreboard\n";
    int size = 0;
    string usernameList[100];

    //! open the file and add a new username to the list
    fstream usersList;
    usersList.open("usersList.txt", ios::in);
    if(usersList.is_open()) { 
        string line;
        while(getline(usersList, line)) {
            usernameList[size] = line;
            size += 1;
        }
        usersList.close();
    }
    //! Save users info to pair array
    pair <string, string>* usersInfo = new pair <string, string>[size];

    for(int i=0; i<size; i++) {
        //! Getting the user info
        fstream user;
        user.open("./accounts/" + usernameList[i] +".txt", ios::in);
        if(user.is_open()){
            string line;
            int count = -1;
            while(getline(user, line)) { //? Storing the user info to an Array
                count += 1;
                if(count == 2) {
                    usersInfo[i].first = usernameList[i];
                    usersInfo[i].second = line;
                }
            }
            user.close();
            cout << "------------------------------------\n";
            cout << usersInfo[i].first << " has " << usersInfo[i].second << " scores.\n";
        }
    }
    cout << "------------------------------------\n";
    system("pause");
}

void AddUserToList(string username) {
    fstream usersList; //? define variable

    //! open the file and add a new username to the list
    usersList.open("usersList.txt", ios::app);
    if(usersList.is_open()) { 
        usersList << username << endl;
        usersList.close();
    }
}

void CurrentUser(string username, string scores) {
    fstream currentUser;

    //! open the file change the current username
    currentUser.open("currentUser.txt", ios::out);
    if(currentUser.is_open()) {
        currentUser << username << endl;
        currentUser << scores;
        currentUser.close();
    }
} 

bool UserExist(string username) {
    //! Checking wether or not a user file exist in the accounts folder
    if(std::filesystem::exists("./accounts/" + username +".txt")) {
        return true;
    }
    else {
        return false;
    }
}

void SignUp() {
    cout << "====================================\n";
    //! define variables need for user infomation
    string username;
    string password;
    string scores = "0";
    bool usernameCheck = false;

    cout << "To sign up, please enter your username and passwords: \n";

    //! Getting the username
    while(!usernameCheck) { //? looping until username is valid
        cout << "Username: ";
        getline(cin, username);

        if(UserExist(username)) {
            cout << "Username alreaedy exist! Please choose a different username.\n";
            Sleep(650);
            return;
        }
        else {
            usernameCheck = true;
        }
    }
    //!Getting the password
    cout << "Password: ";
    getline(cin, password);
    
    //!Creating a new user file
    fstream userFile;
    userFile.open("./accounts/" + username +".txt", ios::out);
    if(userFile.is_open()) {
        userFile << username << endl;
        userFile << password << endl;
        userFile << scores;
        userFile.close();
    }

    CurrentUser(username, "0"); //? Change the current user
    AddUserToList(username); //? Adding the new user to the user lists
    cout << "Signing Up Successful!\n";
    Sleep(650);
}

void Login() {
    cout << "====================================\n";
    //! define the variables needed for login info
    string username;
    string password;

    cout << "To be able to Login please enter your Username and Passwords.\n";

    //! Getting the username
    cout << "Username: ";
    getline(cin, username);
    //! Checking if username actually exist
    if(!std::filesystem::exists("./accounts/" + username +".txt")) {
        cout << "This Username doesn't exist!\n";
        Sleep(650);
        return;
    }
    //! Getting the password
    cout << "Password: ";
    getline(cin, password);

    //! define variables needed for user info
    string userInfo[3];
    fstream user;
    user.open("./accounts/" + username +".txt", ios::in); //? Getting the user info
    if(user.is_open()){
        string line;
        int count = -1;
        while(getline(user, line)) { //? Storing the user info to an Array
            count += 1;
            userInfo[count] = line;
        }
        //! Checking the password
        if(password == userInfo[1]) {
            CurrentUser(username, userInfo[2]);
            cout << "Login Successful!\n";
            Sleep(650);
        } 
        else {
            cout << "Incorrect Password\n";
        }
    }
}

void LogOut() {
    fstream user;
    //! clear out the current user
    user.open("currentUser.txt", ios::out | ios::trunc);
    cout << "Log Out Successful!\n";
    Sleep(650);
}

int main() {
    bool exitProgram = false;
    
    while (!exitProgram) {
        fstream currentUser("currentUser.txt"); //! Checking for current user
        if(currentUser.peek() != EOF) { //! If it the current user file is not empty
            fstream user;
            user.open("currentUser.txt", ios::in);
            if(user.is_open()) {
                //! Getting the current user info from current user file
                string currentUserInfo[2];
                string line;
                int count = 0;
                while(getline(user, line)) { //? Storing the user info to an Array
                    currentUserInfo[count] = line;
                    count++;
                }
                cout << "====================================\n";
                cout << "Welcome, " << currentUserInfo[0] << " (Scores: " << currentUserInfo[1] <<")" << endl;
                    cout << "What would you like to do?\n"; 
                    cout << "[0] Log Out\n";
                    cout << "[1] Play 'Find the Missing Letters!'\n";
                    cout << "[2] Play 'Guess the Correct Number!'\n";
                    cout << "[S] Scoreboard\n";
                    cout << "[X] Exit\n";
                user.close();
                //! Choice Menu
                string choiceString;
                char choice;
                cout << "Your Choice: ";
                getline(cin, choiceString);

                if(choiceString.size() < 2 && choiceString.size() > 0){ //? Validation

                    choice = choiceString[0];
                    switch(toupper(choice)) {
                        case '0':
                            LogOut();
                            break;
                        case '1':
                            GuessTheWord();
                            break;
                        case '2':
                            GuessTheCorrectNumber();
                            break;
                        case 'S':
                            Scoreboard();
                            break;
                        case 'X':
                            exitProgram = true;
                            break;
                        default:
                            cout << "Please input a valid option!\n";
                            break;
                    }
                }
                else {
                    cout << "Please input a valid option!\n";
                }
            }
        }
        else { //! If there are no current user
            fstream usersList("usersList.txt");
            if(usersList.peek() == EOF) { //! If the users list is empty
                cout << "====================================\n";
                cout << "There are no existing accounts on this computer. Do you want to Sign Up?:\n";
                cout << "[0] Sign Up\n";
                cout << "[X] Exit\n";

                //! Choice Menu
                string choiceString;
                char choice;
                cout << "Your Choice: ";
                getline(cin, choiceString);

                if(choiceString.size() < 2 && choiceString.size() > 0){ //? Validation

                    choice = choiceString[0];
                    switch(toupper(choice)) {
                        case '0':
                            SignUp();
                            break;
                        case 'X':
                            exitProgram = true;
                            break;
                        default:
                            cout << "Please input a valid option!\n";
                            break;
                    }
                }
                else {
                    cout << "Please input a valid option!\n";
                }
                    
            }
            else { //! If there are users in the users lists
                cout << "====================================\n";
                cout << "There are existing accounts on this computer. Do you want to Login or Sign Up?:\n";
                cout << "[0] Login\n";
                cout << "[1] Sign Up\n";
                cout << "[X] Exit\n";\

                //! Choice Menu
                string choiceString;
                char choice;
                cout << "Your Choice: ";
                getline(cin, choiceString);

                if(choiceString.size() < 2 && choiceString.size() > 0){ //? Validation

                    choice = choiceString[0];
                    switch(toupper(choice)) {
                        case '0':
                            Login();
                            break;
                        case '1':
                            SignUp();
                            break;
                        case 'X':
                            exitProgram = true;
                            break;
                        default:
                            cout << "Please input a valid option!\n";
                            break;
                    }
                }
                else {
                    cout << "Please input a valid option!\n";
                }
            }
        }
    }
    cout << "Exiting Program...\n";
    Sleep(650);
    return 0;
}