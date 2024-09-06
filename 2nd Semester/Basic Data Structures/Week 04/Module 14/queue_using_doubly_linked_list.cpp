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
            newNode->prev = tail;
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
            head->prev = NULL;
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
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Size: " << q.size() << endl;

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}