#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> symbols(m);
    for (int i = 0; i < m; i++) {
        cin >> symbols[i];
    }
    int t;
    cin >> t;
    map<pair<int, char>, int> trans;
    set<pair<int, char>> checkDuplicate;

    bool valid = true;
    string reason = "";
    for (int i = 0; i < t; i++) {
        int from, to;
        char ch;
        cin >> from >> ch >> to;
        if (from < 0 || from >= n || to < 0 || to >= n) {
            valid = false;
            reason = "State out of range";
        }
        bool found = false;
        for (char s : symbols) {
            if (s == ch) found = true;
        }
        if (!found) {
         valid = false;
         reason = "Invalid symbol in transition";
        }

        if (checkDuplicate.count({from, ch})) {
            valid = false;
            reason = "Duplicate transition";
        }
        checkDuplicate.insert({from, ch});
        trans[{from, ch}] = to;
    }
    int start;
    cin >> start;
    if (start < 0 || start >= n) {
        valid = false;
        reason = "Invalid start state";
    }
    string finalStr;
    cin >> finalStr;
    set<int> finalStates;
    for (char c : finalStr) {
        int f = c - '0';
        if (f < 0 || f >= n) {
        valid = false;
        reason = "Invalid final state";
        }
    finalStates.insert(f);
    }
    for (int i = 0; i < n; i++) {
    for (char s : symbols) {
        if (!trans.count({i, s})) {
        valid = false;
    reason = "Missing Something";
            }
        }
    }

    if (!valid) {
        cout << "Invalid DFA\n";
        cout << reason << endl;
        return 0;
    }
    cout << "Valid DFA\n";
    int q;
    cin >> q;

    while (q--) {
        string input;
        cin >> input;
        int current = start;
        cout << "String: " << input << endl;
        cout << "Path: " << current;
        for (char ch : input) {
            current = trans[{current, ch}];
            cout << " -> " << current;
        }
        cout << endl;
        if (finalStates.count(current)) {
        cout << "Accepted\n";
        } else {
        cout << "Rejected\n";
        }
    }
    return 0;
}
