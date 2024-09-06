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
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head, n);
    }

    Node * temp = head;
    bool isSorted = true;
    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            isSorted = false;
            break;
        }
        temp = temp->next;
    }

    if (isSorted) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}