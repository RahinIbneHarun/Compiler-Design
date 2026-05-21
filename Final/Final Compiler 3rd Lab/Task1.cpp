#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z');
}
bool isValid(string s) {
    if (s.empty()) return false;

    if (s[0] == '|' || s[0] == '*' || s[0] == '+') return false;
    if (s.back() == '|') return false;

    int brackets = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') brackets++;
        if (s[i] == ')') brackets--;
        if (brackets < 0) return false;

        if (i > 0) {
            char p = s[i-1];
            char c = s[i];
            if (c == '|' && p == '|') return false;
            if ((c == '*' || c == '+') && (p == '|' || p == '(')) return false;
        }
    }
    return brackets == 0;
}


string addDots(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        res += s[i];
        if (i + 1 < s.length()) {
            char curr = s[i];
            char next = s[i+1];

            bool currentEndsOperand = (isLetter(curr) || curr == '*' || curr == '+' || curr == ')');
            bool nextStartsOperand = (isLetter(next) || next == '(');

            if (currentEndsOperand && nextStartsOperand) {
                res += '.';
            }
        }
    }
    return res;
}

int getPriority(char c) {
    if (c == '*' || c == '+') return 3;
    if (c == '.') return 2;
    if (c == '|') return 1;
    return 0;
}

string toPostfix(string s) {
    string output = "";
    stack<char> st;

    for (char c : s) {
        if (isLetter(c)) {
            output += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && st.top() != '(' && getPriority(st.top()) >= getPriority(c)) {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        output += st.top();
        st.pop();
    }
    return output;
}

int main() {
    string input;
    cout << "Enter Expression: ";
    cin >> input;

    if (!isValid(input)) {
        cout << "Invalid Expression" << endl;
    } else {
        string dotted = addDots(input);
        string postfix = toPostfix(dotted);

        cout << "Valid Expression" << endl;
        cout << "Normalized: " << dotted << endl;
        cout << "Postfix: " << postfix << endl;
    }
    return 0;
}
