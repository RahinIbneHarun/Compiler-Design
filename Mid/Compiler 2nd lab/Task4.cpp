#include <iostream>
using namespace std;

int main() {
    float num;

    cout << "Enter a number: ";
    cin >> num;

    if (cin.fail()) {
        cout << "invalid" << endl;
    }
    else if (num == (int)num) {
        cout << "integer integral" << endl;
    }
    else {
        cout << "floting integral" << endl;
    }

    return 0;
}
