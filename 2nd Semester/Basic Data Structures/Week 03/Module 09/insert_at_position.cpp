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

int size(Node * head) {
    Node * temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node * &head, Node * &tail, int val) {
    Node * newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
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

void insertAtPosition(Node * head, int pos, int val) {
    Node * newNode = new Node(val);
    Node * temp = head;

    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);
    Node * c = new Node(40);

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    Node * tail = c;

    int pos, val;
    cin >> pos >> val;
    if(pos == 0) {
        insertAtHead(head, tail, val);  
    } else if (pos == size(head)) {
        insertAtTail(head, tail, val);
    } else if(pos > size(head)) {
        cout << "Invalid Index" << endl;
    } else {
        insertAtPosition(head, pos, val);
    }
    printForward(head);
    printBackward(tail);

    return 0;
}