#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName;
    cout << "First name: ";
    cin >> firstName;

    cout << "Last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;
    cout <<"Full name = " << fullName << endl;
    return 0;
}
