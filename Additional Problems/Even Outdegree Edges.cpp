#include <bits/stdc++.h>
using namespace std;
set<int> adj[(int)2e5];
int id[(int)2e5];
bool cmp (int x, int y) {
    if (adj[x].size() == adj[y].size()) {
        return (id[x] < id[y]);
    } else {
        return (adj[x].size() < adj[y].size());
    }
}
void solver (int n) {
    set<int, decltype(cmp)* > pq(cmp);
    vector<int> tester;
    for (int i = 0; i < n; i++) {
        tester.push_back(i);
    }
    random_shuffle(tester.begin(), tester.end());
    for (int i = 0; i < n; i++) {
        id[i] = tester[i];
        pq.insert(i);
    }
    vector<bool> sgn;
    sgn.assign(n, false);
    vector<pair<int,int> > vec;
    while (!pq.empty()) {
        int x = *pq.begin();
        pq.erase(*pq.begin());
        if (adj[x].empty()) {
            continue;
        }
        int y = *adj[x].begin();
        pq.erase(y);
        assert(adj[x].count(y) && adj[y].count(x));
        adj[x].erase(y), adj[y].erase(x);
        if (sgn[x]) {
            vec.push_back(make_pair(x + 1, y + 1));
            sgn[x] = !sgn[x];
        } else {
            vec.push_back(make_pair(y + 1, x + 1));
            sgn[y] = !sgn[y];
        }
        pq.insert(x);
        pq.insert(y);
    }
    for (int i: sgn) {
        if (i) {
            return;
        }
    }
    for (auto& p: vec) {
        cout << p.first << " " << p.second << '\n';
    }
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (m % 2 ) {
        cout << "IMPOSSIBLE";
        exit(0);
    } 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v), adj[v].insert(u);
    }
    int t = 10;
    while (t--) {
        solver(n);
    }
}
