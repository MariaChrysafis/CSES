#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<pair<int,int> > p[2];
    vector<string> res(n);
    int v[2][n];
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            res[i].assign(n, '.');
            cin >> v[j][i];
            p[j].push(make_pair(v[j][i], i));
        }
    }
    while (!p[0].empty()) {
        auto a = p[0].top();
        p[0].pop();
        vector<pair<int,int> > al;
        while (a.first--) {
            auto b = p[1].top();
            res[a.second][b.second] = 'X';
            v[0][a.second]--, v[1][b.second]--;
            al.emplace_back(b.first - 1, b.second);
            p[1].pop();
        }
        for (auto& q: al) {
            p[1].push(q);
        }
    }
    int t = 2;
    while (--t) {
        for (int i: v[t]) {
            if (i) {
                cout << -1;
                exit(0);
            }
        }
    }
    for (auto& s: res) {
        cout << s << '\n';
    }
}
