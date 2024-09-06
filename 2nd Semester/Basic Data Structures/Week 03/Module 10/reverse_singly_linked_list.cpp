#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
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
    tail = newNode;
}



void reverse(Node* &head, Node * curr) {
    if(curr->next == NULL) {
        head = curr;
        return;
    }

    reverse(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;
}

void reverse2(Node * &head) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node * curr = head;
    Node * prev = NULL;

    while(curr != NULL) {
        Node * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    reverse(head, head);
    printForward(head);
    reverse2(head);
    printForward(head);


    return 0;
}