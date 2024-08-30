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

void deleteHead(Node * &head) {
    if (head == NULL) {
        return;
    }
    Node * toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void deleteTail(Node * &tail) {
    if (tail == NULL) {
        return;
    }
    Node * toDelete = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete toDelete;
}

void deleteAtPosition(Node * &head, Node * &tail, int pos) {
    if (head == NULL) {
        return;
    }
    if (pos == 0) {
        deleteHead(head);
        return;
    }
    if (pos == size(head) - 1) {
        deleteTail(tail);
        return;
    }
    if (pos < 0 || pos >= size(head)) {
        cout << "Invalid Position" << endl;
        return;
    }
    Node * temp = head;
    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }
    Node * toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    toDelete->next = NULL;
    toDelete->prev = NULL;
    delete toDelete;
}

int main() {
    Node * head = NULL;
    Node * tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    deleteAtPosition(head, tail, 3);
    deleteHead(head);
    deleteTail(tail);
    printForward(head);
    printBackward(tail);

    return 0;
}