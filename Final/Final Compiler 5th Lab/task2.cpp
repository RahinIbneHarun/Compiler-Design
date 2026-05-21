#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct DFA {
    int n;
    map<pair<int, char>, int> transitions;
    int start_state;
    set<int> final_states;
};

int main() {
    int m;
    cin >> m;
    vector<char> alphabet(m);
    for (int i = 0; i < m; ++i) cin >> alphabet[i];

    DFA d1;
    cin >> d1.n;
    for (int i = 0; i < d1.n * m; ++i) {
        int u, v;
        char c;
        cin >> u >> c >> v;
        d1.transitions[{u, c}] = v;
    }
    cin >> d1.start_state;
    int f1;
    cin >> f1;
    for (int i = 0; i < f1; ++i) {
        int s; cin >> s;
        d1.final_states.insert(s);
    }

    DFA d2;
    cin >> d2.n;
    for (int i = 0; i < d2.n * m; ++i) {
        int u, v;
        char c;
        cin >> u >> c >> v;
        d2.transitions[{u, c}] = v;
    }
    cin >> d2.start_state;
    int f2;
    cin >> f2;
    for (int i = 0; i < f2; ++i) {
        int s; cin >> s;
        d2.final_states.insert(s);
    }

    string op;
    cin >> op;
    int q;
    cin >> q;
    vector<string> test_strings(q);
    for (int i = 0; i < q; ++i) cin >> test_strings[i];

    cout << "Product DFA Start State:" << endl;
    cout << "(" << d1.start_state << "," << d2.start_state << ")" << "\n" << endl;

    cout << "Product DFA Final States:" << endl;
    bool first_f = true;
    for (int i = 0; i < d1.n; ++i) {
        for (int j = 0; j < d2.n; ++j) {
            bool is_f1 = d1.final_states.count(i);
            bool is_f2 = d2.final_states.count(j);
            bool is_final = (op == "union") ? (is_f1 || is_f2) : (is_f1 && is_f2);

            if (is_final) {
                if (!first_f) cout << " ";
                cout << "(" << i << "," << j << ")";
                first_f = false;
            }
        }
    }
    cout << "\n" << endl;

    cout << "Product DFA Transition Table:" << endl;
    for (int i = 0; i < d1.n; ++i) {
        for (int j = 0; j < d2.n; ++j) {
            for (char c : alphabet) {
                int next1 = d1.transitions[{i, c}];
                int next2 = d2.transitions[{j, c}];
                cout << "(" << i << "," << j << ") --" << c << "--> (" << next1 << "," << next2 << ")" << endl;
            }
        }
    }
    cout << endl;

    for (const string& s : test_strings) {
        int curr1 = d1.start_state;
        int curr2 = d2.start_state;
        for (char c : s) {
            curr1 = d1.transitions[{curr1, c}];
            curr2 = d2.transitions[{curr2, c}];
        }

        bool is_f1 = d1.final_states.count(curr1);
        bool is_f2 = d2.final_states.count(curr2);
        bool accepted = (op == "union") ? (is_f1 || is_f2) : (is_f1 && is_f2);

        cout << "String: " << s << endl;
        cout << (accepted ? "Accepted" : "Rejected") << "\n" << endl;
    }

    return 0;
}
