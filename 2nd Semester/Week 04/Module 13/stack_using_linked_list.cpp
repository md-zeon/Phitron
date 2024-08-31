#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack {
    Node* head;
    Node* tail;
    int sz;
public:
    Stack() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sz++;
    }

    void pop() {
        if (head == NULL) {
            return;
        } else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        sz--;
    }

    int top() {
        if (head == NULL) {
            return -1;
        } else {
            return tail->data;
        }
    }

    bool empty() {
        if (head == NULL) {
            return true;
        } else {
            return false;
        }
    }

    int size() {
        return sz;
    }

};

int main() {
    Stack s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        s.push(data);
    }
    cout << "Size = " << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << "Size = " << s.size() << endl;
    

    return 0;
}