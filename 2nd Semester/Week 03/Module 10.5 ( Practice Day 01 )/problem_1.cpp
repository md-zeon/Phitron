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

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* tail1 = NULL;
    Node* tail2 = NULL;
    int val;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter List 1 values: ";
    cin >> val;
    int size1 = 0, size2 = 0;
    while(val != -1) {
        insertAtTail(head1, tail1, val);
        size1++;
        cin >> val;
    }

    cout << "Enter -1 to exit" << endl;
    cout << "Enter List 2 values: ";
    cin >> val;
    while(val != -1) {
        insertAtTail(head2, tail2, val);
        size2++;
        cin >> val;
    }

    bool same = true;

    if(size1 != size2) {
        same = false;
    } else {
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != NULL) {
            if(temp1->data != temp2->data) {
                same = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    cout << (same ? "YES" : "NO") << endl;

    return 0;
}