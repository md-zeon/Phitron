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
    cout << endl << "Inserted at Tail" << endl << endl;
}

void insertAtPosition(Node* &head, int pos, int d) {
    Node *newNode = new Node(d);
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp -> next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << endl << "Inserted at Position " << pos << endl << endl;
}

void insertAtHead(Node *&head, int d) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    Node *newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
    cout << endl << "Inserted at Head" << endl << endl;
}

int main() {
    Node *head = NULL;
    while (true) {
        int op;
        cout << "Option 01: Insert at Tail\n";
        cout << "Option 02: Print Linked List\n";
        cout << "Option 03: Insert at Position\n";
        cout << "Option 04: Insert at Head\n";
        cout << "Option 05: Exit\n";
        cout << "Enter your option: ";
        cin >> op;
        if (op == 1) {
            int d;
            cin >> d;
            insertAtTail(head, d);
        } else if (op == 2) {
            printLinkedList(head);
        } else if (op == 3) {
            int pos, d;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter data: ";
            cin >> d;
            if(pos == 0) {
                insertAtHead(head, d);
            } else {
                insertAtPosition(head, pos, d);
            }
        }
        else if (op == 4) {
            int d;
            cin >> d;
            insertAtHead(head, d);
        } else if (op == 5) {
            break;
        }
    }

    return 0;
}