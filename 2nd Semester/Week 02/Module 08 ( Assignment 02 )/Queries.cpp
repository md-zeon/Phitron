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

void insertAtHead(Node * &head, Node* &tail, int data) {
    Node * newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node * &head, Node* &tail, int data) {
    Node * newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int main() {
    int q;
    cin >> q;

    Node * head = NULL;
    Node * tail = NULL;

    while(q--) {
        int x, val;
        cin >> x >> val;

        if(x == 0) {
            insertAtHead(head, tail, val);
        } else {
            insertAtTail(head, tail, val);
        }

        cout << head->data << " " << tail->data << endl;
    }

    return 0;
}



//! TIME LIMIT EXCEEDED IN A TEST CASE