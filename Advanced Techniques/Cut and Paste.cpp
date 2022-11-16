#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* left;
    Node* right;
    int x, y, sz;
    Node (int x, int y) {
        this->left = nullptr, this->right = nullptr, this->x = x, this->y = y, this->sz = 1;
    }
    Node (int x) {
        this->left = nullptr, this->right = nullptr, this->x = x, this->y = rand(), this->sz = 1;
    }
};
Node* root;
string s;
int f (Node* x) {
    return (x == nullptr ? 0 : x->sz); 
}
void print (Node*x) {
    if (x == nullptr) return;
    print(x->left);
    cout << s[x->x];
    print(x->right);
}
void upd (Node* x) {
    x->sz = f(x->left) + f(x->right) + 1;
}
Node* merge (Node* left, Node*right) {
    if (left == nullptr || right == nullptr) {
        return ((left == nullptr) ? right : left);
    }
    if (left->y < right->y) {
        left->right = merge(left->right, right);
        upd(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        upd(right);
        return right;
    }
}
pair<Node*, Node*> split (Node*cur, int x) {
    if (f(cur) == x) {
        return make_pair(cur, nullptr);
    }
    if (f(cur->left) >= x) {
        auto p = split(cur->left, x);
        cur->left = p.second;
        upd(cur);
        return make_pair(p.first, cur);
    } else {
        auto p = split(cur->right, x - f(cur->left) - 1);
        cur->right = p.first;
        upd(cur);
        return make_pair(cur, p.second);
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        root = merge(root, new Node(i));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto p = split(root, l);
        auto q = split(p.second, r - l + 1);
        root = merge(p.first, merge(q.second, q.first));
    }
    print(root);
}
