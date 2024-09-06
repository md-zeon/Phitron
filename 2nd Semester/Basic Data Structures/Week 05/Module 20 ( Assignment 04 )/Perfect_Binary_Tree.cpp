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

bool isPerfect(Node* root) {
    if(root == nullptr) return true;
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if(root->left == nullptr || root->right == nullptr) {
        return false;
    }

    return isPerfect(root->left) && isPerfect(root->right);
}


int main() {
    Node* root = input_tree();
    if(isPerfect(root)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}