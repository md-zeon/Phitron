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

Node* reverse(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head = prev;

    return head;
}

bool isPalindrome(Node* head) {
    if (head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* temp1 = head;
    Node* temp2 = reverse(slow);

    while (temp2 != NULL) {
        if(temp1->data != temp2->data) {
            return false;
        } else {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
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

    cout << (isPalindrome(head) ? "YES" : "NO") << endl;

    return 0;
}