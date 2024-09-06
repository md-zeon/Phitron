//* LEET CODE: 225. Implement Stack using Queues

//* LINK: https://leetcode.com/problems/implement-stack-using-queues/description/


#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;
    int last;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> newQ;
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty()) {
                last = k;
                break;
            }
            newQ.push(k);
        }
        q = newQ;
        return last;
    }
    
    int top() {
        queue<int> newQ;
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            if (q.empty()) {
                last = k;
            }
            newQ.push(k);
        }
        q = newQ;
        return last;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


#include <queue>
using namespace std;

class MyStack2 {
private:
    queue<int> q;
public:
    MyStack2() {
        
    }
    
    void push(int x) {
        q.push(x);
        // Rotate the queue to make the last element the front
        int size = q.size();
        while (size-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
