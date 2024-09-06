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

    Node * temp = head;
    int mid = size / 2;

    for (int i = 0; i < mid-1; i++) {
        temp = temp->next;
    }
    
    if(size % 2 == 0) {
        cout << temp->data << " " << temp->next->data;
    } else {
        cout << temp->next->data;
    }

    return 0;
}