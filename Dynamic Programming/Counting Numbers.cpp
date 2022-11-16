#include <bits/stdc++.h>
using namespace std;
map<int64_t,int64_t> dp[20][12][2];
vector<int64_t> powr;
int64_t solve (int prev, int64_t r, int d, bool beginning) {
    //cout << prev << " " << r << " " << d << '\n';
    assert(prev >= -1);
    if (d <= 0 || r < 0) {
        return 0;
    }
    if (dp[d][prev + 1][beginning].count(r))  {
        return dp[d][prev + 1][beginning][r];
    }
    if (r <= 9) {
        int cntr = 0;
        for (int x = 0; x <= r; x++) {
            cntr += (x != prev);
        }
        if (d == 1) {
            return cntr;
        }
        if (d == 2) {
            cntr -= (0 != prev);
            return cntr;
        }
        return 0;
    }
    int64_t first_digit = r/powr[d - 1];
    string str = to_string(r);
    int64_t ans = 0;
    if (beginning) {
        ans = solve(-1, powr[(int)str.size() - 1] - 1, d - 1, true);
    }
    if (first_digit != prev) {
        string s = str;
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());
        ans += solve(first_digit, stoll(s), d - 1, false);
    }
    int64_t cntr = 0;
    for (int64_t x = beginning; x < first_digit; x++) {
        cntr += (x != prev);
    }
    ans += solve(0, powr[str.length() - 1] - 1, d - 1, false) * cntr;
    dp[d][prev + 1][beginning][r] = ans;
    return ans;
}
int64_t solver (int64_t a) {
    return solve(-1, a, (to_string(a)).size(), true);
}
int main() {
    powr.push_back(1);
    for (int i = 0; i < 18; i++) {
        powr.push_back(powr.back() * 10ll);
    }
    int64_t x, y;
    cin >> x >> y;
    cout << solver(y) - solver(x - 1) << '\n';
}
