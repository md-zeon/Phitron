#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void insertAtTail(Node * &head, Node * &tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


void printMaximumMinimumNode(Node * head) {
    Node * temp = head;
    int mx = INT_MIN;
    int mn = INT_MAX;

    while (temp != NULL) {
        mx = max(mx, temp->data);
        mn = min(mn, temp->data);
        temp = temp->next;
    }

    cout << mx << " " << mn << endl;
}


int main() {
    Node * head = NULL;
    Node * tail = NULL;

    int val;
    cin >> val;

    while (val != -1) {
        insertAtTail(head, tail, val);
        cin >> val;
    }

    printMaximumMinimumNode(head);

    return 0;
}