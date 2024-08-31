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

int size(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printFromHead(Node* head) {
    Node* temp = head;
    cout << "L -> ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void printFromTail(Node* tail) {
    Node* temp = tail;
    cout << "R -> ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int val) {
    Node* newNode = new Node(val);
    if(pos == 0) {
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            printFromHead(head);
            printFromTail(tail);
            return;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            printFromHead(head);
            printFromTail(tail);
            return;
        }
    } else if (pos == size(head)) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        printFromHead(head);
        printFromTail(tail);
        return;
    } else if (pos < 0 || pos > size(head)) {
        cout << "Invalid" << endl;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printFromHead(head);
    printFromTail(tail);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int q;
    cin >> q;
    while (q--) {
        int pos, val;
        cin >> pos >> val;
        insertAtPosition(head, tail, pos, val);
    }

    return 0;
}