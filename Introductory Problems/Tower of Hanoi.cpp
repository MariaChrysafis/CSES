#include <bits/stdc++.h>
using namespace std;
void rec (int n, int a, int b, int c) {
    if (n--) {
        rec(n, a, c, b);
        cout << a << " " << c << '\n';
        rec(n, b, a, c);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    rec(n, 1, 2, 3);
}
