//* LEET CODE: 232. Implement Queue using Stacks

//* LINK: https://leetcode.com/problems/implement-queue-using-stacks/description/


#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> newS;
        int last;
        while (!s.empty()) {
            int k = s.top();
            s.pop();
            if(s.empty()) {
                last = k;
                break;
            }
            newS.push(k);
        }
        while (!newS.empty()) {
            s.push(newS.top());
            newS.pop();
        }
        return last;
    }
    
    int peek() {
        stack<int> newS;
        int last;
        while (!s.empty()) {
            int k = s.top();
            s.pop();
            if(s.empty()) {
                last = k;
            }
            newS.push(k);
        }
        while (!newS.empty()) {
            s.push(newS.top());
            newS.pop();
        }
        return last;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
private:
    stack<int> stack1, stack2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }
    
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};
