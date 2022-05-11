#include <iostream>

using namespace std;

int addNumber(int a, int b) {
    return a + b;
}

bool isPostive(int n) {
    if(n > 0) {
        return true;
    }
    else {
        return false;
    }
}

void AddNumberProgram() {
    int a;
    int b;

    cout << "Add Number: " << endl;
    cout << "Enter number for a: ";
    cin >> a;

    if(isPostive(a)) {

        cout << "Enter number for b: ";  
        cin >> b;
        
        if(isPostive(b)) {
            cout << "A + B = " << addNumber(a, b) << endl;
        }
    }
}

int main() {

    AddNumberProgram();

    return 0;
}