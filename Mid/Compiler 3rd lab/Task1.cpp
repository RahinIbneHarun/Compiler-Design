#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void checkExpression2(string s) {
    if (s.length() != 3) {
        cout << "Invalid" << endl;
        return;
    }
    if (isalpha(s[0])) {
        if ((s[1] == '+' && s[2] == '+') || (s[1] == '-' && s[2] == '-')) {
        cout << "Valid" << endl;
        return;
        }
    }
    else if (isalpha(s[2])) {
        if ((s[0] == '+' && s[1] == '+') || (s[0] == '-' && s[1] == '-')) {
        cout << "Valid" << endl;
        return;
        }
    }
    cout << "Invalid" << endl;
}

int main() {
    string userInput;
    cout << "Enter an expression to check: ";
    cin >> userInput;
    cout << "Expected Output: ";
    checkExpression2(userInput);

    return 0;
}
