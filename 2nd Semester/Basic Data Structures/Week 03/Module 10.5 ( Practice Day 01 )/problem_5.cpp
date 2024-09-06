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



void printList(Node * head) {
    if(head == NULL) {
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}


void sort(Node * head) {
    for (Node * i = head; i->next != NULL; i = i->next) {
        for (Node * j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                swap(i->data, j->data);
            }
        }
    }
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

    sort(head);
    printList(head);

    return 0;
}