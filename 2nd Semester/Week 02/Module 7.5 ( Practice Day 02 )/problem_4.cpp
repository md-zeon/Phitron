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


int maximumNode(Node * head) {
    Node * temp = head;
    int m = INT_MIN;

    while (temp != NULL) {
        m = max(m, temp->data);
        temp = temp->next;
    }

    return m;
}


int main() {
    Node * head = NULL;
    Node * tail = NULL;

    int val;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter values: ";
    cin >> val;

    while (val != -1) {
        insertAtTail(head, tail, val);
        cin >> val;
    }

    cout << maximumNode(head) << endl;

    return 0;
}