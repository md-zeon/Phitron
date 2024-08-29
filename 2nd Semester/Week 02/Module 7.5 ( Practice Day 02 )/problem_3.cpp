#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void insertAtTail(Node * &head, Node * &tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}



int main() {
    Node * head = NULL;
    Node * tail = NULL;

    int val;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter values: ";
    cin >> val;
    int cnt = 0;
    while (val != -1) {
        insertAtTail(head, tail, val);
        cnt++;
        cin >> val;
    }

    int mid = cnt / 2;

    Node * temp = head;

    for (int i = 0; i < mid-1; i++) {
        temp = temp->next;
    }

    if(cnt % 2 == 0) {
        cout << temp->data << " " << temp->next->data;
    } else {
        cout << temp->next->data;
    }

    return 0;
}