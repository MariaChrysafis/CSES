#include <bits/stdc++.h>
int main() {
    int64_t n, k;
    std::cin >> n >> k;
    std::deque<int> d;
    while(n) {
        d.push_front(n--);
    }
    while (!d.empty()) {
        std::cout << ((k >= d.size() - 1) ? d.back() : d.front()) << ' ';
        if (k >= d.size() - 1) {
            k -= d.size() - 1;
            d.pop_back();
        } else {
            d.pop_front();
        }
    }
}
