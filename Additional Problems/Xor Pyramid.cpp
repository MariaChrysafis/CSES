#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bitset<(int)100010> bs;
    bs.set(0);
    for (int i = 0; i < n - 1; i++) {
        bs = bs ^ (bs << 1);
    }
    int64_t x = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i < 100010) {
            if (bs[i]) {
                x ^= a;
            }
        } else {
            if (bs[n - i - 1]) {
                x ^= a;
            }
        }
    }
    cout << x;
}
