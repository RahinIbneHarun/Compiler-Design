#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;


    char symbols[100];
    for (int i = 0; i < m; i++) {
        cin >> symbols[i];
    }

    int t;
    cin >> t;

    int from[200], to[200];
    char ch[200];
    for (int i = 0; i < t; i++) {
        cin >> from[i] >> ch[i] >> to[i];
    }
    int start;
    cin >> start;
    int f;
    cin >> f;
    int finalStates[100];
    for (int i = 0; i < f; i++) {
        cin >> finalStates[i];
    }

    string input;
    cin >> input;


    vector<int> currentStates;
    currentStates.push_back(start);


    for (int i = 0; i < input.size(); i++) {
        vector<int> nextStates;

        for (int j = 0; j < currentStates.size(); j++) {
            int curr = currentStates[j];

            for (int k = 0; k < t; k++) {
                if (from[k] == curr && ch[k] == input[i]) {
                    nextStates.push_back(to[k]);
                }
            }
        }

        currentStates = nextStates;
    }

    bool accepted = false;
    for (int i = 0; i < currentStates.size(); i++) {
        for (int j = 0; j < f; j++) {
            if (currentStates[i] == finalStates[j]) {
                accepted = true;
        }
    }
    }

    if (accepted)
        cout << "Accepted";
    else
        cout << "Rejected";

    return 0;
}
