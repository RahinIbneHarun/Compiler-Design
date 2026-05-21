#include <iostream>
using namespace std;

int main() {
    int a[] = {7, -2, 15, 4, 9};
    int size = 5;
  int min = a[0];
    int max = a[0];

for (int i = 1; i < size; i++) {
        if (a[i] < min) {
        min = a[i];
    }
    if (a[i] > max) {
    max = a[i];
    }
    }
 cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;

    return 0;
}
