#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pair<int64_t,pair<int,int> > > vec;
    set<int> s;
    for (int i = 0; i < t; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        s.insert(x), s.insert(y);
        vec.push_back(make_pair(cost, make_pair(x, y)));
    }
    int cntr = 0;
    map<int,int> myMap;
    for (int i: s) {
        myMap[i] = cntr++;
    }
    vector<int> indices[myMap.size()];
    for (int i = 0; i < vec.size(); i++) {
        vec[i].second.first = myMap[vec[i].second.first];
        vec[i].second.second = myMap[vec[i].second.second];
        indices[vec[i].second.second].push_back(i);
    }
    int64_t dp[myMap.size() + 1];
    dp[0] = 0;
    for (int i = 1; i <= myMap.size(); i++) {
        dp[i] = dp[i - 1];
        for (int j: indices[i - 1]) {
            assert(vec[j].second.second == i - 1);
            dp[i] = max(dp[i], dp[vec[j].second.first] + vec[j].first);
        }
    }
    cout << dp[myMap.size()] << '\n';
}
