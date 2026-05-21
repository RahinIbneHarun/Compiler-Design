#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
   int count = 0;
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == '(' || c == ')' || c == '{' || c == '}' ||
            c == '[' || c == ']' || c == ',' || c == ';') {
            count++;
            cout << "delimiter" << count << " : " << c << endl;
        }
    }
    cout << "Number of delimiters = " << count << endl;

    return 0;
}
