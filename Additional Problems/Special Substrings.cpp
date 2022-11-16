#include <bits/stdc++.h>
using namespace std;
vector<int> reduce (vector<int> &v) {
    int myMin = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        myMin = min(myMin, v[i]);
    }
    for (int i = 0; i < v.size(); i++) {
        if (myMin) v[i]--;
    }
    return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    char c = 'a';
    map<char,char> myMap;
    for (int i = 0; i < s.size(); i++) {
        if (!myMap.count(s[i])) {
            myMap[s[i]] = c++;
        } 
        s[i] = myMap[s[i]];
    }
    vector<int> tot;
    tot.assign(myMap.size(), 0);
    map<char,int> cnt;
    map<vector<int>,int> m;
    m[tot]++;
    int64_t ans = 0;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
        tot[s[i] - 'a']++;
        reduce(tot);
        ans += m[tot]++;
    }
    cout << ans << '\n';
}
