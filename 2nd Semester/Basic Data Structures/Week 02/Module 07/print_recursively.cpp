#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(Node * &head, Node* &tail, int val) {
    Node * newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void printLinkedList(Node * head) {
    Node * temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printRecursively(Node * n) {
    if (n == NULL) {
        return;
    }
    cout << n->data << " ";
    printRecursively(n->next);
}

void printReverseRecursively(Node * n) {
    if (n == NULL) {
        return;
    }
    printReverseRecursively(n->next);
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

    // printLinkedList(head);

    printRecursively(head);
    cout << endl;
    printReverseRecursively(head);

    return 0;
}