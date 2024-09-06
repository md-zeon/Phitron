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

int main() {
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    Node * tail = b;

    printForward(head);
    printBackward(tail);

    return 0;
}