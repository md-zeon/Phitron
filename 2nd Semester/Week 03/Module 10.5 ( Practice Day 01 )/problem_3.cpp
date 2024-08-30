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

bool isPalindrome(Node * head, Node * tail) {
    if(head == NULL || head->next == NULL) {
        return true;
    }
    Node * i = head;
    Node * j = tail;

    while (i != j && i->next != j) {
        if(i->data != j->data) {
            return false;
        }
        i = i->next;
        j = j->prev;
    }

    if(i->data != j->data) {
        return false;
    }

    return true;
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

    cout << (isPalindrome(head, tail) ? "YES" : "NO") << endl;



    return 0;
}