#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cin >> n;
    while (n != -1) {
        insertAtTail(head, tail, n);
        cin >> n;
    }

    for(Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                swap(i->data, j->data);
            }
        }
    }

    Node* temp = head;

    while(temp != NULL) {
        if(temp->next != NULL && temp->next->data == temp->data) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }

    temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}