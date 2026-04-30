#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    int count = 0;

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];


        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
            ch == '[' || ch == ']' || ch == ',' || ch == ';') {

            count++;
            cout << "delimiter" << count << " : " << ch << endl;
        }
    }

    cout << "number of delimiters = " << count << endl;

    return 0;
}
