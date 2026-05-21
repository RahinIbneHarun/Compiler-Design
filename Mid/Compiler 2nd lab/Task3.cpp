#include <iostream>
#include <string>
using namespace std;

int main() {
    string token;
    cin >> token;
    if (token == "int" || token == "float" || token == "double" ||
        token == "char" || token == "if" || token == "else" ||
        token == "while" || token == "return") {
        cout << "Keyword" << endl;
    }
    else if (isalpha(token[0]) || token[0] == '_') {
    bool valid = true;
    for (int i = 1; i < token.length(); i++) {
    if (!isalnum(token[i]) && token[i] != '_') {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "Identifier" << endl;
        else
            cout << "Invalid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }

    return 0;
}
