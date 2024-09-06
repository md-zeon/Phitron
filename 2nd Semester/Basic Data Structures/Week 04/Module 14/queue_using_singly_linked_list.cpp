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

class Queue {
private:
    Node* head;
    Node* tail;
    int sz;
public:
    Queue() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void pop() {
        if(head == NULL) {
            return;
        } else if(head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        sz--;
    }

    int front() {
        if(head == NULL) {
            return -1;
        }
        return head->data;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }
};

int main() {
    Queue q;
    int n;
    cin >> n; // 5
    while(n--) {
        int x;
        cin >> x;
        q.push(x); // 10 20 30 40 50
    }

    while(!q.empty()) {
        cout << q.front() << " "; // 10 20 30 40 50
        q.pop();
    }

    cout << endl;
    cout << q.size() << endl; // 0
    cout << q.empty() << endl; // 1
    cout << q.front() << endl; // -1

    return 0;
}