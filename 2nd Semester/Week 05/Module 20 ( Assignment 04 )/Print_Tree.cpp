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

void printTree(Node* root) {
    if(root == nullptr) return;
    queue<Node*> q;
    if(root) q.push(root);
    stack<int> s;

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        s.push(p->data);

        if(p->right) {
            q.push(p->right);
        }

        if(p->left) {
            q.push(p->left);
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}


int main() {
    Node* root = input_tree();

    printTree(root);

    return 0;
}