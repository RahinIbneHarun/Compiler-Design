#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string varName;
    cout << "Enter variable name: ";
    cin >> varName;

    string keywords[] = {"int", "float", "double", "char", "if", "else", "for", "while"};

    if (isdigit(varName[0])) {
        cout << "Invalid variable name" << endl;
        return 0;}
   for (string keyword : keywords) {
        if (varName == keyword) {
            cout << "Invalid variable name" << endl;
            return 0;
    }
    }
    for (char ch : varName) {
        if (!isalnum(ch) && ch != '_' && ch != '$') {
            cout << "Invalid variable name" << endl;
            return 0;
    }
    }
    cout << "Valid variable name" << endl;
    return 0;
}
