#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k * k < n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        int c = 0;
        for (int j = 0; j <= n/k; j++) {
            int c1 = 0;
            for (int i = min(k, n - c); i >= 1; i--) {
                c1++;
                cout << k * j + i << ' ';
            }
            c += c1;
        }
        cout << '\n';
    } 
}
