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

void printLinkedList(Node* head) {
    cout << endl;
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl << endl;
}

void insertAtTail(Node* &head, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}


void insertAtHead(Node *&head, int d) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    Node *newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
}



int main() {
    Node *head = NULL;
    while (true) {
        int val;
        cin >> val;
        if (val == -1) {
            break;
        }
        insertAtTail(head, val);
    }
    printLinkedList(head);

    return 0;
}