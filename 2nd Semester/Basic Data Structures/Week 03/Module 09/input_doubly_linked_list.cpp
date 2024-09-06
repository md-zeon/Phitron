#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void printForward(Node * head) {
    Node * temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(Node * tail) {
    Node * temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}


void insertAtTail(Node * &head, Node * &tail, int val) {
    Node * newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
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

    printForward(head);
    printBackward(tail);

    return 0;
}