#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void printLinkedList(Node * head) {
    Node * temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node * &head, Node* &tail, int val) {
    Node * newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node * &head, Node* &tail, int val) {
    Node * newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


void deleteHead(Node * &head) {
    if (head == NULL) {
        cout << "List is empty. No head to delete." << endl;
        return;
    }
    Node * temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}


void deleteTail(Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "List is empty. No tail to delete." << endl;
        return;
    }
    if (head->next == NULL) {  // Only one node in the list
        deleteHead(head);
        tail = NULL;  // After deletion, both head and tail should be NULL
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    tail = temp;
    delete toDelete;
}



void deleteNode(Node * &head, Node * &tail, int pos) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // Count the total number of nodes in the list
    int length = 0;
    Node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Check if the position is out of range
    if (pos < 0 || pos >= length) {
        cout << "Invalid position. No node exists at position " << pos << "." << endl;
        return;
    }

    // Deleting the head node
    if (pos == 0) {
        deleteHead(head);
        // Update tail if necessary
        if (head == NULL) {
            tail = NULL;
        }
        return;
    }

    // Traverse to the node just before the one to be deleted
    temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    // If deleting the tail node
    if (temp->next == tail) {
        deleteTail(head, tail);
        return;
    }

    // Deleting a middle node
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    toDelete->next = NULL;
    delete toDelete;
}



int main() {
    Node * head = NULL;
    Node * tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtHead(head, tail, 0);
    insertAtTail(head, tail, 50);

    printLinkedList(head);

    deleteNode(head, tail, 0);
    printLinkedList(head);
    deleteNode(head, tail, 3);
    printLinkedList(head);
    deleteNode(head, tail, 4);
    printLinkedList(head);

    return 0;
}