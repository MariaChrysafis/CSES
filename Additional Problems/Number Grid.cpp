#include <bits/stdc++.h>
int main() {
    int n, m, ans = 0;
    std::cin >> n >> m;
    n--, m--;
    int64_t N = (1ll << 31);
    while (N != 1) {
        N /= 2;
        ans += N * (n/N != m/N);
        n %= N, m %= N;
    }
    std::cout << ans;
}
