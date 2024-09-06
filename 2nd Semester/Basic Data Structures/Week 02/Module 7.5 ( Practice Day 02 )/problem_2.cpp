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


void printReverseList(Node * n) {
    if (n == NULL) {
        return;
    }
    printReverseList(n->next);
    cout << n->data << " ";
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

    printReverseList(head);


    return 0;
}