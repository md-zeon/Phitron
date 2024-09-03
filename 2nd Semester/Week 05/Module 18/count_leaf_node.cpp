#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1) root = NULL;
     else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while (!q.empty()) {
        // 1. ber kore ano
        Node* p = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache koro
        int l, r;
        cin >> l >> r;
        Node* left, *right;
        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1) 
            right = NULL;
        else 
            right = new Node(r);

        p->left = left;
        p->right = right;

        // 3. children gulo ke push koro

        if (p->left) {
            q.push(p->left);
        }

        if (p->right) {
            q.push(p->right);
        }
    }

    return root;
}

void levelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is Empty" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        // get the first element
        Node* f = q.front();
        q.pop();
        // print the data of the first element
        cout << f->data << " ";
        // push the children of the first element
        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
}


int count_leaf(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        // leaf
        return 1;
    } else {
        // left + right
        return count_leaf(root->left) + count_leaf(root->right);
    }
}


int main() {
    Node* root = input_tree();

    levelOrder(root);
    cout << endl;
    cout << count_leaf(root) << endl;
    

    return 0;
}