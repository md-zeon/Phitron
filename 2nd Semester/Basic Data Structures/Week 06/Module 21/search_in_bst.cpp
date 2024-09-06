#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        int left_data, right_data;
        cin >> left_data;
        if (left_data != -1) {
            temp->left = new Node(left_data);
            q.push(temp->left);
        }
        cin >> right_data;
        if (right_data != -1) {
            temp->right = new Node(right_data);
            q.push(temp->right);
        }
    }

    return root;
}


void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* parent = q.front();
        cout << parent->data << " ";
        q.pop();

        if (parent->left) {
            q.push(parent->left);
        }

        if (parent->right) {
            q.push(parent->right);
        }
    }
}

bool search(Node* root, int x) {
    if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }

    if (x < root->data) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

int main() {
    Node* root = input_tree();
    levelOrder(root);

    cout << endl;

    int x;
    cin >> x;

    if(search(root, x)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    

    return 0;
}