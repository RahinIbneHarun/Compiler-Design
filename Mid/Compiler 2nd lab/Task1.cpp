#include <iostream>
#include <string>

using namespace std;
int main() {
    string input;
    string target = " -,+,/,*,^,$,<,>,!,=";
    int count = 0;
    cout << "Enter an expression  :";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
     for (int j = 0; j < target.length(); j++) {
      if (input[i] == target[j]) {
        count++;
            cout << "operator" << count << " : " << input[i] << endl;
            break;
        }
    }
    }
  cout << "Number of operators = " << count << endl;
   return 0;
}

