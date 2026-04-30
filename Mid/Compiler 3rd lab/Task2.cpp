#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool validateExpression(string str) {

    bool expectOperand = true;
    bool hasSeenChar = false;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isspace(c)) continue;
        hasSeenChar = true;

        if (expectOperand) {

        if (isalpha(c)) {
            expectOperand = false;
        } else {
            return false;
        }
        } else {

        if (c == '+' || c == '-' || c == '*' || c == '/') {
        expectOperand = true;
        } else {
                return false;
            }
        }
    }
    return hasSeenChar && !expectOperand;
}

int main() {
    string input;
    getline(cin, input);

    if (validateExpression(input)) {
    cout << "Valid" << endl;
    } else {
    cout << "Invalid" << endl;
    }

    return 0;
}
