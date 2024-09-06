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

Node* convert(vector<int>& arr, int si, int ei) {
    if(si > ei) {
        return NULL;
    }

    int mid = (si + ei) / 2;
    Node* root = new Node(arr[mid]);

    root->left = convert(arr, si, mid-1);
    root->right = convert(arr, mid+1, ei);

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = convert(arr, 0, n - 1);
    levelOrder(root);

    return 0;
}
