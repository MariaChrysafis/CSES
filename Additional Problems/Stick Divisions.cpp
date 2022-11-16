#include <bits/stdc++.h>
using namespace std;
int main() {
    int64_t n, x;
    cin >> x >> n;
    int64_t v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    priority_queue<int64_t> pq;
    for (int i: v) {
        pq.push(-i);
    }
    int64_t ans = 0;
    while (pq.size() != 2) {
        int64_t a = pq.top();
        pq.pop();
        int64_t b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    ans += pq.top();
    pq.pop();
    ans += pq.top();
    cout << -ans;
}
