#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int size = 5;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + a[i];
    }
    float average = sum / size;
    cout << "Average value = " << average << endl;

    return 0;
}
