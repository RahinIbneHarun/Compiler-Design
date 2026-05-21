#include <iostream>
using namespace std;

int n, m, t;
int from[200], to[200];
char ch[200];

bool visited[100];

void eClosure(int state, int closure[], int &size) {
    visited[state] = true;
    closure[size++] = state;

    for (int i = 0; i < t; i++) {
        if (from[i] == state && ch[i] == 'e') {
            if (!visited[to[i]]) {
                eClosure(to[i], closure, size);
    }
    }
    }
}

int main() {
    cin >> n >> m;

    char symbols[100];
    for (int i = 0; i < m; i++) {
        cin >> symbols[i];
    }

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> from[i] >> ch[i] >> to[i];
    }
    for (int i = 0; i < n; i++) {
        int closure[100];
        int size = 0;

        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }

        eClosure(i, closure, size);

        cout << "Epsilon closure of " << i << " = {";
        for (int j = 0; j < size; j++) {
            cout << closure[j];
            if (j != size - 1) cout << ",";
        }
        cout << "}" << endl;
    }

    int k;
    cin >> k;

    int stateSet[100];
    for (int i = 0; i < k; i++) {
        cin >> stateSet[i];
    }
    char inputSymbol;
    cin >> inputSymbol;
    int moveSet[100];
    int moveSize = 0;
    for (int i = 0; i < k; i++) {
        int curr = stateSet[i];

    for (int j = 0; j < t; j++) {
        if (from[j] == curr && ch[j] == inputSymbol) {
     bool exists = false;
        for (int x = 0; x < moveSize; x++) {
            if (moveSet[x] == to[j]) {
            exists = true;
        break;
        }
            }
        if (!exists) {
                    moveSet[moveSize++] = to[j];
            }
        }
    }
    }
    cout << "Move({";
    for (int i = 0; i < k; i++) {
    cout << stateSet[i];
    if (i != k - 1) cout << ",";
    }
    cout << "}, " << inputSymbol << ") = {";

    for (int i = 0; i < moveSize; i++) {
        cout << moveSet[i];
        if (i != moveSize - 1) cout << ",";
    }
    cout << "}" << endl;

    return 0;
}
