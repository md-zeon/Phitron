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
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

int main() {
    Node * head = NULL;
    vector<int> freq(101, 0);
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head, n);
        freq[n]++;
    }

    bool duplicate = false;
    for (int i = 0; i < 101; i++) {
        if (freq[i] > 1) {
            duplicate = true;
            break;
        }
    }

    if (duplicate) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}