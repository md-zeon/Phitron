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

int treeSum(Node* root) {
    if(!root) return 0;
    return root->data + treeSum(root->left) + treeSum(root->right);
}

int main() {
    Node* root = input_tree();
    
    cout << treeSum(root);

    return 0;
}