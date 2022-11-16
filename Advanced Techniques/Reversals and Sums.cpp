#include <bits/stdc++.h>
using namespace std;
struct Node {
    bool rev;
    int64_t val;
    int64_t sum;
    int sz;
    int y;
    bool val1;
    Node* left;
    Node* right;
    Node (int64_t val) {
        this->val = val;
        sum = val, rev = false;
        left = nullptr, right = nullptr;
        y = rand(), sz = 1, val1 = false;
    }
};
void upd (Node*& x) {
    if (x->rev) {
        swap(x->left, x->right);
        if (x->left != nullptr) {
            x->left->rev ^= 1;
        }
        if (x->right != nullptr) {
            x->right->rev ^= 1;
        }
        x->rev = false;
    }
    if (x->val1) {
        if (x->left != nullptr) {
            x->left->val1 = true;
            x->left->val = x->val;
        }
        if (x->right != nullptr) {
            x->right->val1 = true;
            x->right->val = x->val;
        }
        x->val1 = false;
    }
    x->sum = ((x->left != nullptr) ? x->left->sum : 0) + x->val + ((x->right != nullptr) ? x->right->sum : 0);
    x->sz = ((x->left != nullptr) ? x->left->sz : 0) + 1 + ((x->right != nullptr) ? x->right->sz : 0);
}
Node* merge (Node* left, Node*right) {
    if (left == nullptr || right == nullptr) {
        return ((left == nullptr) ? right : left);
    }
    upd(left), upd(right);
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
 
int f (Node* x) {
    if (x == nullptr) return 0;
    upd(x);
    return x->sz;
}
 
pair<Node*, Node*> split (Node*cur, int x) {
    if (cur != nullptr) upd(cur);
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
 
void print (Node*x) {
    if (x == nullptr) return;
    print(x->left);
    upd(x);
    cout << x->val << ' ';
    print(x->right);
}
 
int64_t get_sum (Node* root, int l, int r) {
    auto p = split(root, l);
    auto q = split(p.second, r - l + 1);
    upd(q.first);
    int64_t ans = q.first->sum;
    root = merge(p.first, merge(q.first, q.second));
    return ans;
}
 
Node* insert (Node* root, int l, int64_t x) {
    auto p = split(root, l + 1);
    root = merge(merge(p.first, new Node(x)), p.second);
    return root;
}
 
Node* to_delete (Node* root, int l, int r) {
    auto p = split(root, l);
    auto q = split(p.second, r - l + 1);
    root = merge(p.first, q.second);
    return root;
}
 
Node* to_reverse (Node*root, int l, int r) {
    auto p = split(root, l);
    auto q = split(p.second, r - l + 1);
    q.first->rev = q.first->rev ^ 1;
    root = merge(p.first, merge(q.first, q.second));
    return root;
}
 
Node* modify (Node*root, int l, int r, int64_t x) {
    auto p = split(root, l);
    auto q = split(p.second, r - l + 1);
    q.first->val1 = true, q.first->val = x;
    root = merge(p.first, merge(q.first, q.second));
    return root;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    Node*root = nullptr;
    for (int i = 0; i < n; i++) {
        int64_t x; cin >> x;
        root = insert(root, i -1 , x);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 2) {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << get_sum(root, l, r) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            root = to_reverse(root, l, r);
        }
    }
    /*
    int n, q;
    cin >> n >> q;
    Node* root;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, i - 1, x);
    }
    while (q--) {
        string s; cin >> s;
        if (s == "GET-SUM") {
            int l, sz;
            cin >> l >> sz;
            l--;
            cout << get_sum(root, l, l + sz - 1) << '\n';
        } else if (s == "INSERT") {
            int pos; cin >> pos; pos--;
            int sz; cin >> sz;
            for (int i = pos; i <= pos + sz - 1; i++) {
                int x; cin >> x;
                root = insert(root, i, x);
            }
        } else if (s == "DELETE") {
            int l, sz;
            cin >> l >> sz;
            l--;
            root = to_delete(root, l, l + sz - 1);
        } else if (s == "REVERSE") {
            int l, sz;
            cin >> l >> sz;
            l--;
            root = to_reverse(root, l, l + sz - 1);
        } else if (s == "MAKE-SAME") {
            int l, sz, x;
            cin >> l >> sz >> x;
            l--;
            root = modify(root, l, l + sz - 1, x);
        } else {
            cout << 10 << '\n';
        }
    }
    */
 
}
