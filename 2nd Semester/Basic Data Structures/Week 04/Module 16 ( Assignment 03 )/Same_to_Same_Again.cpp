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

class Stack {
    Node* head;
    int size;
public:

    Stack() {
        head = NULL;
        size = 0;
    }

    void push(int data) {

        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop() {
        if (size == 0) return;

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int top() {
        if (size == 0) {
            return -1;
        }
        return head->data;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size;
public:

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int data) {

        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop() {
        if (size == 0) return;

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int front() {
        if (size == 0) {
            return -1;
        }
        return head->data;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Stack s;
    while (n--) {
        int x;
        cin >> x;
        s.push(x);
    }

    Queue q;
    while (m--) {
        int x;
        cin >> x;
        q.push(x);
    }

    bool same = true;

    if(s.getSize() != q.getSize()) {
        same = false;
    } else {
        while (!s.empty()) {
            if (s.top() != q.front()) {
                same = false;
                break;
            }
            s.pop();
            q.pop();
        }
    }

    cout << (same ? "YES" : "NO") << endl;

    return 0;
}