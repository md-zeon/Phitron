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

void printLevel(Node* root, int x) {
    if(root == nullptr) return;
    queue<pair<Node*, int>> q;
    if(root) q.push({root, 0});
    bool isValid = false;

    while(!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* node = p.first;
        int level = p.second;

        if(level == x) {
            cout << node->data << " ";
            isValid = true;
        }

        if(node->left) {
            q.push({node->left, level + 1});
        }

        if(node->right) {
            q.push({node->right, level + 1});
        }
    }

    if(!isValid) cout << "Invalid";

}


int main() {
    Node* root = input_tree();
    int x;
    cin >> x;
    printLevel(root, x);

    return 0;
}