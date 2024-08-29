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

int size(Node * head) {
    if (head == NULL) {
        return 0;
    }

    Node * temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


int main() {
    Node * head1 = NULL;
    Node * tail1 = NULL;

    int val;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter values: ";
    cin >> val;

    while (val != -1) {
        insertAtTail(head1, tail1, val);
        cin >> val;
    }
    // cout << "List 01 Added Successfully\n";

    Node * head2 = NULL;
    Node * tail2 = NULL;
    cout << "Enter -1 to exit" << endl;
    cout << "Enter values: ";
    cin >> val;

    while (val != -1) {
        insertAtTail(head2, tail2, val);
        cin >> val;
    }
    // cout << "List 02 Added Successfully\n";

    int size1 = size(head1);
    int size2 = size(head2);

    if (size1 == size2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}