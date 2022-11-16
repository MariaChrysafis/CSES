#include <bits/stdc++.h>
#define u long long
const int M = 1e9 + 7;
std::vector<u> f = {1};
u b (u x, u y) {
    int64_t r = x % M, a = 1;
    while (y) {
        if (y & 1) {
            a *= r, a %= M;
        }
        r *= r, r %= M, y /= 2;
    }
    return a;
}
int main() {
    u n, k, a, m;
    std::cin >> n >> k;
    while(f.size() != n + 1) {
        f.push_back((f.back() * f.size()) % M);
    }
    a = 0, m = k;
    while(m) {
        a += (b(f[m] * f[k - m], M - 2) * b(m, n)) % M * (int)pow(-1, k - m) + M;
        a %= M, m--;
    }
    std::cout << (a * f[k]) % M;
}
