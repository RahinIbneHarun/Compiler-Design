#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
typedef set<int> StateSet;

void printSet(StateSet s) {
    if (s.empty()) {
    cout << "{}";
    return;
    }
    cout << "{";
    auto it = s.begin();
    while (it != s.end()) {
        cout << *it;
        if (++it != s.end()) cout << ",";
    }
    cout << "}";
}
StateSet getEClosure(StateSet states, int n, vector<pair<int, pair<char, int>>>& trans) {
    StateSet closure = states;
    bool changed = true;
    while (changed) {
    changed = false;
    for (auto& t : trans) {
        int u = t.first;
        char symbol = t.second.first;
        int v = t.second.second;
if (symbol == 'e' && closure.count(u) && !closure.count(v)) {
        closure.insert(v);
        changed = true;
            }
        }
    }
    return closure;
}
StateSet getMove(StateSet states, char symbol, vector<pair<int, pair<char, int>>>& trans) {
    StateSet res;
    for (int s : states) {
        for (auto& t : trans) {
            if (t.first == s && t.second.first == symbol) {
                res.insert(t.second.second);
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> alphabet(m);
    for (int i = 0; i < m; i++) cin >> alphabet[i];

    int t_count;
    cin >> t_count;
    vector<pair<int, pair<char, int>>> transitions;
    for (int i = 0; i < t_count; i++) {
        int u, v; char c;
        cin >> u >> c >> v;
        transitions.push_back({u, {c, v}});
    }

    int startNode; cin >> startNode;
    int f_count; cin >> f_count;
    set<int> nfaFinals;
    for (int i = 0; i < f_count; i++) {
        int f; cin >> f;
        nfaFinals.insert(f);
    }

    map<StateSet, map<char, StateSet>> dfaTable;
    vector<StateSet> dfaStates;
    queue<StateSet> q;

    StateSet startSet = getEClosure({startNode}, n, transitions);
    q.push(startSet);
    dfaStates.push_back(startSet);

    int head = 0;
    while(head < dfaStates.size()){
        StateSet curr = dfaStates[head++];
for(char sym : alphabet) {
        StateSet next = getEClosure(getMove(curr, sym, transitions), n, transitions);
        dfaTable[curr][sym] = next;
bool found = false;
for(auto& s : dfaStates) if(s == next) found = true;
            if(!found) dfaStates.push_back(next);
        }
    }

    cout << "Start State = "; printSet(startSet); cout << endl;

    cout << "Final States: ";
    for(auto& s : dfaStates) {
        for(int state : s) {
            if(nfaFinals.count(state)) {
                printSet(s); cout << " ";
                break;
            }
        }
    }
    cout << "\nTransition Table:\n";
    for(auto& s : dfaStates) {
        for(char sym : alphabet) {
            printSet(s); cout << " --" << sym << "--> ";
            printSet(dfaTable[s][sym]); cout << endl;
        }
    }
    int queries; cin >> queries;
    while(queries--) {
        string str; cin >> str;
        StateSet curr = startSet;
        for(char c : str) curr = dfaTable[curr][c];

        bool accepted = false;
        for(int s : curr) if(nfaFinals.count(s)) accepted = true;
        cout << "String: " << str << " " << (accepted ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
