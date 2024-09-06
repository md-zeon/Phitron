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

void printForward(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void printBackward(Node* tail) {
    Node* temp = tail;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void insertAtHead(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

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

int size(Node* head) {
    Node * temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int val) {

    if(pos == 0) {
        insertAtHead(head, tail, val);
        printForward(head);
        printBackward(tail);
        return;
    } else if (pos == size(head)) {
        insertAtTail(head, tail, val);
        printForward(head);
        printBackward(tail);
        return;
    }

    if(pos < 0 || pos > size(head)) {
        cout << "Invalid" << endl;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    printForward(head);
    printBackward(tail);
}




int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int q;
    cin >> q;

    while(q--) {
        int x, val;
        cin >> x >> val;
        insertAtPosition(head, tail, x, val);
    }


    return 0;
}