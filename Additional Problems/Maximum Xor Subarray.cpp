#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* child[2];
    int d;
    Node () {
        child[0] = child[1] = nullptr;
    }
};
Node* root;
void add_node (int x) {
    Node* cur = root;
    for (int i = 31; i >= 0; i--) {
        bool b = (x & (1 << i));
        if (cur->child[b] == nullptr) {
            cur->child[b] = new Node();
        }
        cur = cur->child[b];
    }
}
int best (Node*cur, int x, int bt) {
    bool b = (x & (1 << bt));
    if (cur->child[0] == nullptr && cur->child[1] == nullptr) {
        return 0;
    }
    if (cur->child[!b] != nullptr) {
        return best(cur->child[!b], x, bt - 1) + (1 << bt);
    } else {
        return best(cur->child[b], x, bt - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root = new Node();
    int n;
    cin >> n;
    int pref = 0;
    int myMax = 0;
    add_node(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref ^= x;
        myMax = max(myMax,best(root, pref, 31));
        add_node(pref);
    }
    cout << myMax;
}
