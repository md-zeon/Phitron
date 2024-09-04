#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* input_tree() {
    int x;
    cin >> x;
    if(x == -1) return nullptr;
    Node *root = new Node(x);
    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty()) {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if(l != -1) {
            p->left = new Node(l);
            q.push(p->left);
        }
        if(r != -1) {
            p->right = new Node(r);
            q.push(p->right);
        }
    }
    return root;
}

pair<int, int> maxMinLeaf(Node* root, pair<int, int> &p) {
    if(root == NULL) {
        return p;
    }

    if(root->left == NULL && root->right == NULL) {
        p.first = max(p.first, root->data);
        p.second = min(p.second, root->data);
        return p;
    }

    maxMinLeaf(root->left, p);
    maxMinLeaf(root->right, p);

    return p;
}

int main() {
    Node* root = input_tree();
    pair<int, int> p = {INT_MIN, INT_MAX};
    maxMinLeaf(root, p);
    cout << p.first << " " << p.second;

    return 0;
}