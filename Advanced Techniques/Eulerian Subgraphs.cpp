#include <bits/stdc++.h>
using namespace std;
vector<set<int> > adj;
set<int> vis;
void dfs (int x) {
    vis.insert(x);
    for (int i: adj[x]) {
        if (!vis.count(i)) {
            dfs (i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v), adj[v].insert(u);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i: adj[x]) {
            adj[i].erase(x);
            if (adj[i].size() == 1) {
                q.push(i);
            }
        }
        adj[x].clear();
    }
    int e = 0, v = 0, cntr = 0;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[i].empty()) {
            continue;
        }
        v++;
        e += adj[i].size();
        if (!vis.count(i)) {
            dfs(i), cntr++;
        }
    }
    e /= 2;
    cntr += e - v;
    int64_t powr = 1;
    while (cntr--) {
        powr *= 2, powr %= (int)1e9 + 7;
    }
    cout << powr;
}
