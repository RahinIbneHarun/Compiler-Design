#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
string formatGroup(const vector<int>& states) {
string s = "{";
for (int i = 0; i < states.size(); ++i) {
s += to_string(states[i]);
if (i < (int)states.size() - 1) s += ",";
}
s += "}";
return s;
}
int main() {
int n, m;
if (!(cin >> n >> m)) return 0;vector<string> symbols(m);
map<string, int> symIndex;
for (int i = 0; i < m; ++i) {
cin >> symbols[i];
symIndex[symbols[i]] = i;
}
vector<vector<int>> adj(n, vector<int>(m));
for (int i = 0; i < n * m; ++i) {
int curr, next;
string sym;
cin >> curr >> sym >> next;
adj[curr][symIndex[sym]] = next;
}
int start_node;
cin >> start_node;
int f_count;
cin >> f_count;
vector<bool> is_final(n, false);
for (int i = 0; i < f_count; ++i) {
int f;
cin >> f;
is_final[f] = true;
}
vector<int> group(n);
int num_groups = 0;
if (f_count < n) num_groups++;
if (f_count > 0) num_groups++;
int non_final_id = 0, final_id = (f_count < n) ? 1 : 0;
for (int i = 0; i < n; ++i) group[i] = is_final[i] ? final_id : non_final_id;
while (true) {
vector<int> new_group(n);
map<pair<int, vector<int>>, int> partition_map;
int next_id = 0;
for (int i = 0; i < n; ++i) {
vector<int> move_to;
for (int j = 0; j < m; ++j) move_to.push_back(group[adj[i][j]]);
pair<int, vector<int>> sig = {group[i], move_to};
if (partition_map.find(sig) == partition_map.end()) partition_map[sig] = next_id++;
new_group[i] = partition_map[sig];
}
if (next_id == num_groups) break;
group = new_group;num_groups = next_id;
}
vector<vector<int>> equiv_groups(num_groups);
for (int i = 0; i < n; ++i) equiv_groups[group[i]].push_back(i);
vector<string> group_names(num_groups);
vector<bool> group_is_final(num_groups, false);
for (int i = 0; i < num_groups; i++) {
group_names[i] = formatGroup(equiv_groups[i]);
group_is_final[i] = is_final[equiv_groups[i][0]];
}
cout << "Equivalent Groups:" << endl;
for (int i = 0; i < num_groups; i++) cout << group_names[i] << endl;
cout << "Start State = " << group_names[group[start_node]] << endl;
cout << "Final States:" << endl;
for (int i = 0; i < num_groups; i++) if (group_is_final[i]) cout << group_names[i] << " ";
cout << "\nMinimized DFA Transition Table:" << endl;
vector<vector<int>> min_adj(num_groups, vector<int>(m));
for (int i = 0; i < num_groups; i++) {
int representative = equiv_groups[i][0];
for (int j = 0; j < m; j++) {
min_adj[i][j] = group[adj[representative][j]];
cout << group_names[i] << " --" << symbols[j] << "--> " << group_names[min_adj[i][j]] << endl;
}
}
int q;
cin >> q;
while (q--) {
string input;
cin >> input;
cout << "String: " << input << endl;
cout << "Path: " << group_names[group[start_node]];
int current_g = group[start_node];
bool possible = true;
for (char c : input) {
string s(1, c);
if (symIndex.find(s) == symIndex.end()) {
possible = false;
break;
}
current_g = min_adj[current_g][symIndex[s]];
cout << " -> " << group_names[current_g];
}
if (possible && group_is_final[current_g]) cout << "\nAccepted" << endl;else cout << "\nRejected" << endl;
}
return 0;
}
