#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "This is a program to dsiplay a multiplication table.";
    cout << "\nEnter maxium size: ";
    cin >> size;

    for (int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    return 0;
}