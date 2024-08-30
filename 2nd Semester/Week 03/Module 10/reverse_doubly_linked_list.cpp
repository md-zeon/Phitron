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

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}



void reverse(Node* head, Node* tail) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node* i = head;
    Node* j = tail;

    while(i != j && i->next != j) {
        swap(i->data, j->data);
        i = i->next;
        j = j->prev;
    }
    swap(i->data, j->data);
}


void printForward(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}




int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    reverse(head, tail);
    printForward(head);


    return 0;
}