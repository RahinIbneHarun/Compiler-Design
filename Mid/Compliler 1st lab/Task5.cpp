#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;
    ofstream outFile("students.txt");
 for (int i = 0; i < n; i++) {
        string name;
        int marks;
        cout << "Student " << i + 1 << " name: ";
        cin >> name;
        cout << "Student " << i + 1 << " marks: ";
        cin >> marks;

        outFile << name << " " << marks << endl;
    }
    outFile.close();
    cout << "\nData read from file:" << endl;
    ifstream inFile("students.txt");
    string name;
    int marks;
  while (inFile >> name >> marks) {
        cout << name << " " << marks << endl;
    }
   inFile.close();
   return 0;
}
