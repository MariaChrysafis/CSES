#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t n;
    cin >> n;
    int64_t l = 0;
    int64_t r = n * n;
    while (l != r) {
        int64_t m = (l + r)/2;
        int64_t x = 0;
        for (int i = 1; i <= n; i++) {
            x += min(m/i, n);
        }
        if (x >= n * n/2 + 1) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l;
}
