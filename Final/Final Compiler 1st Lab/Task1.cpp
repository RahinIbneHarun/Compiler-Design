#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Step 1: Enter number of states and symbols : ";
    if (!(cin >> n >> m)) return 0;

    cout << "Step 2: Enter the symbols one by one : " << endl;
    for (int i = 0; i < m; i++) {
        char sym; cin >> sym;
    }
    int stateTable[100][256];
    for(int i = 0; i < 100; i++) {
     for(int j = 0; j < 256; j++) stateTable[i][j] = -1;
    }

    int t;
    cout << "Step 3: Enter number of transitions : ";
    cin >> t;
    cout << "Step 4: Enter transitions (Format: current_state symbol next_state):" << endl;
    for (int i = 0; i < t; i++) {
        int u, v;
        char symbol;
        cin >> u >> symbol >> v;
        stateTable[u][(int)symbol] = v;
    }

    int startState, f;
    cout << "Step 5: Enter start state : ";
    cin >> startState;
    cout << "Step 6: Enter number of final states: ";
    cin >> f;

    int finalStates[100];
    cout << "Step 7: Enter the final state(s): ";
    for (int i = 0; i < f; i++) {
        cin >> finalStates[i];
    }

    cout << "\n--- DFA Setup Complete ---" << endl;
    cout << "Enter the string to check then tell accpet or reject: ";

    string input;
    while (cin >> input && input != "exit") {
        int currentState = startState;
        bool possible = true;
        for (char c : input) {
        if (stateTable[currentState][(int)c] != -1) {
        currentState = stateTable[currentState][(int)c];
            } else {
        possible = false;
        break;
        }
        }
    bool accepted = false;
        if (possible) {
        for (int i = 0; i < f; i++) {
        if (currentState == finalStates[i]) {
        accepted = true;
        break;
            }
        }
    }
        if (accepted) cout << ">> RESULT: Accepted" << endl;
        else cout << ">> RESULT: Rejected" << endl;
        cout << "\nEnter another string to check : ";
    }

    return 0;
}
