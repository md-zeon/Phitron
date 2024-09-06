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

void printLinkedList(Node * head) {
    if(head == NULL) {
        return;
    }
    cout << head->data << " ";
    printLinkedList(head->next);
}

void printReverseLinkedList(Node * n) {
    if(n == NULL) {
        return;
    }
    printReverseLinkedList(n->next);
    cout << n->data << " ";
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

    printReverseLinkedList(head);
    cout << endl;
    printLinkedList(head);
    

    return 0;
}