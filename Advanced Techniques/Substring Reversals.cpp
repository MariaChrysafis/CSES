#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* left;
    Node* right;
    int x, y, sz;
    bool b;
    Node (int x, int y) {
        this->left = nullptr, this->right = nullptr, this->x = x, this->y = y, this->sz = 1, this->b = false;
    }
    Node (int x) {
        this->left = nullptr, this->right = nullptr, this->x = x, this->y = rand(), this->sz = 1, this->b = false;
    }
};
Node* root;
string s;
int f (Node* x) {
    return (x == nullptr ? 0 : x->sz); 
}
void push (Node*& x) {
    if (!x->b) return;
    x->b = !x->b;
    swap(x->left, x->right);
    if (x->left != nullptr) x->left->b = !x->left->b;
    if (x->right != nullptr) x->right->b = !x->right->b;
}
void print (Node*x) {
    if (x == nullptr) return;
    push(x);
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
    push(left), push(right);
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
    push(cur);
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
        q.first->b = !q.first->b;
        root = merge(p.first, merge(q.first, q.second));
    }
    print(root);
}
