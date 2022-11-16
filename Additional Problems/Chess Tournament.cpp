#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    priority_queue<pair<int,int> > pq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(make_pair(arr[i], i));
    }
    vector<pair<int,int > > edges;
    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        if (p.first < 0) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        pq.pop();
        vector<pair<int,int> > later;
        while (p.first--) {
            pair<int,int> q = pq.top();
            pq.pop();
            edges.push_back(make_pair(q.second + 1, p.second + 1));
            later.push_back(make_pair(q.first - 1, q.second));
        }
        for (auto& q: later) {
            pq.push(q);
        }
    }
    cout << edges.size() << '\n';
    for (auto& p: edges) {
        cout << p.first << " " << p.second << '\n';
    }
}
