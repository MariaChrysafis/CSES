#include <iostream>
#include <vector>
using namespace std;
vector<int> oc;
string ans;
int maxv (vector<int> &v) {
    int mx = 0;
    for (int i: v) {
        mx = max(mx, i);
    }
    return mx;
}
int f (vector<int> &v, int o) {
    int c = 0;
    for (int i: v) {
        if (o == i) {
            c++;
        }
    }
    return c;
}
int sum (vector<int>& v) {
    int sum = 0;
    for (int i: v) {
        sum += i;
    }
    return sum;
}
void rec (int c) {
    int mx = maxv(oc);
    int ind = f(oc, mx);
    int sm = sum(oc);
    for (int pos = 0; pos < 26; pos++) {
        if (pos == c or oc[pos] == 0) {
            continue;
        }
        oc[pos] -= 1;
        bool okay = true;
        if (ind == pos) {
            if (maxv(oc) > sm/2) {
                okay = false;
            }
        } else {
            if (maxv(oc) > sm/2) {
                okay = false;
            }
        }
        if (not okay) {
            oc[pos] += 1;
            continue;
        }
        ans += 'A' + pos;
        rec(pos);
        return;
    }
}
int main () {
    oc.assign(26, 0);
    string s;
    cin >> s;
    for (char c: s) {
        oc[c - 'A']++;
    }
    int mx = maxv(oc);
    if (mx > (s.length() + 1)/2) {
        cout << -1;
        exit(0);
    }
    rec(-1);
    cout << ans;
}
