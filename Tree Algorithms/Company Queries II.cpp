#include <cmath>
#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <type_traits>
#include <string>
#include <queue>
#define ll long long
#include <map>
 
using namespace std;
class Tree {
protected:
    vector<vector<int>> adj;
    vector<vector<int>> dp;
    vector<int> pre, post;
    int cntr = 0;
    void dfs (int curNode, int prevNode) {
        pre[curNode] = cntr++;
        dp[curNode][0] = prevNode;
        for (int i: adj[curNode]) {
            if (i != prevNode) {
                dfs(i, curNode);
            }
        }
        post[curNode] = cntr++;
    }
public:
    Tree (int n) {
        adj.resize(n), pre.resize(n), post.resize(n), dp.resize(n, (vector<int>(log2(n) + 1)));
    }
    void add_edge (int u, int v) {
        adj[u].push_back(v), adj[v].push_back(u);
    }
    int isAncestor (int u, int v) {
        return (pre[u] <= pre[v] && post[u] >= post[v]);
    }
    int lca (int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = dp[u].size() - 1; i >= 0; i--) {
            if (!isAncestor(dp[u][i], v)) {
                u = dp[u][i];
            }
        }
        return dp[u][0];
    }
    void read() {
        dfs(0, 0);
        for (int j = 1; j < dp[0].size(); j++) {
            for (int i = 0; i < dp.size(); i++) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }
};
int main() {
    int n;
    cin >> n;
    Tree t(n);
    int q;
    cin >> q;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        x--;
        t.add_edge(i + 1, x);
    }
    t.read();
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << t.lca(--a, --b) + 1 << '\n';
    }
 
 
}
