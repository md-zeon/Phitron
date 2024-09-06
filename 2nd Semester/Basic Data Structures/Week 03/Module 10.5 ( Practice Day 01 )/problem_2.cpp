#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
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

void reverse(Node* &head, Node * curr) {
    if(curr->next == NULL) {
        head = curr;
        return;
    }

    reverse(head, curr->next);

    curr->next->next = curr;
    curr->next = NULL;
}


void printList(Node * head) {
    if(head == NULL) {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter values: ";
    cin >> val;
    while(val != -1) {
        insertAtTail(head, tail, val);
        cin >> val;
    }

    reverse(head, head);
    printList(head);



    return 0;
}