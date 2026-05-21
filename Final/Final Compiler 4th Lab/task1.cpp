#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
struct Transition {
int next_state;};
int main() {
int n, m;
if (!(cin >> n >> m)) return 0;
vector<string> symbols(m);
for (int i = 0; i < m; ++i) cin >> symbols[i];
vector<vector<int>> adj(n, vector<int>(m));
for (int i = 0; i < n * m; ++i) {
int curr, next;
string sym;
cin >> curr >> sym >> next;
for (int j = 0; j < m; ++j) {
if (symbols[j] == sym) adj[curr][j] = next;
}
}
int start_state;
cin >> start_state;
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
for (int i = 0; i < n; ++i) {
group[i] = is_final[i] ? final_id : non_final_id;
}
while (true) {vector<int> new_group(n);
map<pair<int, vector<int>>, int> partition_map;
int next_id = 0;
for (int i = 0; i < n; ++i) {
vector<int> move_to;
for (int j = 0; j < m; ++j) {
move_to.push_back(group[adj[i][j]]);
}
pair<int, vector<int>> signature = {group[i], move_to};
if (partition_map.find(signature) == partition_map.end()) {
partition_map[signature] = next_id++;
}
new_group[i] = partition_map[signature];
}
if (next_id == num_groups) break;
group = new_group;
num_groups = next_id;
}
vector<vector<int>> equiv_groups(num_groups);
for (int i = 0; i < n; ++i) {
equiv_groups[group[i]].push_back(i);
}
auto get_group_str = [&](int state_idx) {
int g_id = group[state_idx];
string s = "{";
for (int i = 0; i < equiv_groups[g_id].size(); ++i) {
s += to_string(equiv_groups[g_id][i]);
if (i < (int)equiv_groups[g_id].size() - 1) s += ",";
}
s += "}";
return s;
};
cout << "Equivalent Groups:" << endl;
for (auto& g : equiv_groups) {
cout << "{";for (int i = 0; i < g.size(); ++i) {
cout << g[i] << (i == g.size() - 1 ? "" : ",");
}
cout << "}" << endl;
}
cout << "Start State = " << get_group_str(start_state) << endl;
cout << "Final States:" << endl;
set<int> printed_finals;
for (int i = 0; i < n; i++) {
if (is_final[i] && printed_finals.find(group[i]) == printed_finals.end()) {
cout << get_group_str(i) << " ";
printed_finals.insert(group[i]);
}
}
cout << endl;
cout << "Minimized DFA Transition Table:" << endl;
set<int> visited_groups;
for (int i = 0; i < n; i++) {
if (visited_groups.find(group[i]) == visited_groups.end()) {
for (int j = 0; j < m; j++) {
cout << get_group_str(i) << " --" << symbols[j] << "--> " << get_group_str(adj[i][j])
<< endl;
}
visited_groups.insert(group[i]);
}
}
return 0;
}
