#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int64_t> pq;
    int64_t n, ans = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t x;
        cin >> x;
        pq.push(x);
        ans += pq.top() - x;
        pq.pop(), pq.push(x);
    }
    cout << ans;
}
