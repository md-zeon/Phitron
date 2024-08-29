#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
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

int main() {
    Node *head = NULL;
    while (true) {
        int op;
        cout << "Option 01: Insert at Tail\n";
        cout << "Option 02: Print Linked List\n";
        cout << "Option 03: Exit\n";
        cout << "Enter your option: ";
        cin >> op;
        if (op == 1) {
            int d;
            cin >> d;
            insertAtTail(head, d);
        } else if (op == 2) {
            printLinkedList(head);
        } else if (op == 3) {
            break;
        }
    }
    return 0;
}