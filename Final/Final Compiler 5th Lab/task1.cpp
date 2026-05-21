#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<char> symbols(m);
    for (int i = 0; i < m; ++i) {
        cin >> symbols[i];
    }

    vector<map<char, int>> transitions(n);
    for (int i = 0; i < n * m; ++i) {
        int curr, next;
        char sym;
        cin >> curr >> sym >> next;
        transitions[curr][sym] = next;
    }

    int start_state;
    cin >> start_state;

    int f;
    cin >> f;
    set<int> original_final_states;
    for (int i = 0; i < f; ++i) {
        int state;
        cin >> state;
        original_final_states.insert(state);
    }


    vector<int> complement_final_states;
    for (int i = 0; i < n; ++i) {
        if (original_final_states.find(i) == original_final_states.end()) {
            complement_final_states.push_back(i);
        }
    }

    cout << "Complement Final States:" << endl;
    for (int i = 0; i < complement_final_states.size(); ++i) {
        cout << complement_final_states[i] << (i == complement_final_states.size() - 1 ? "" : " ");
    }
    cout << "\n" << endl;

    int q;
    cin >> q;
    while (q--) {
        string test_str;
        cin >> test_str;

        int current = start_state;
        bool possible = true;

        for (char c : test_str) {
            if (transitions[current].count(c)) {
                current = transitions[current][c];
            } else {

                possible = false;
                break;
            }
        }

        cout << "String: " << test_str << endl;


        bool is_final_in_complement = true;
        if (original_final_states.find(current) != original_final_states.end()) {
            is_final_in_complement = false;
        }

        if (possible && is_final_in_complement) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
        cout << endl;
    }

    return 0;
}
