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
    cin >> val;
    int n = 0;
    while (val != -1) {
        insertAtTail(head, tail, val);
        n++;
        cin >> val;
    }

    for (Node * i = head; i->next != NULL; i = i->next) {
        for (Node * j = i->next; j != NULL; j = j->next) {
            if( i->data < j->data) {
                swap(i->data, j->data);
            }
        }
    }

    if (n == 1) {
        cout << head->data << endl;
    } else {
        int mid = n / 2;
        Node * temp = head;
        for (int i = 0; i < mid-1; i++) {
            temp = temp->next;
        }
        
        if(n % 2 == 0) {
            cout << temp->data << " " << temp->next->data << endl;
        } else {
            cout << temp->next->data << endl;
        }
    }
    

    return 0;
}