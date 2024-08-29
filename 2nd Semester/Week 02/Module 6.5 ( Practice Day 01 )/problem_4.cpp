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

void printLinkedList(Node* &head) {
    Node * temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtTail(Node * &head, int data) {
    Node * newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node * temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtIndex(Node * &head, int idx, int data) {
    Node * newNode = new Node(data);
    if (idx == 0) {
        newNode->next = head;
        head = newNode;
        printLinkedList(head);
        return;
    }
    Node * temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "Invalid" << endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printLinkedList(head);
}

int main() {
    Node * head = NULL;
    int size = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head, n);
        size++;
    }

    int q;
    cin >> q;

    while (q--) {
        int idx, data;
        cin >> idx >> data;
        insertAtIndex(head, idx, data);
    }

    return 0;
}