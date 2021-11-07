//
// Created by BrandonZu on 2021/7/8.
//

#include "common.h"

class MyStack {
    queue<int> myQ;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = myQ.size();
        myQ.push(x);
        for(int i = 0; i < size; i++) {
            myQ.push(myQ.front());
            myQ.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = myQ.front();
        myQ.pop();
        return result;
    }

    /** Get the top element. */
    int top() {
        return myQ.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQ.empty();
    }
};

// 1st Review 09/29/21
// Runtime 0ms(>100%) | Memory Usage 6.8MB(>89%)
class MyStack_R1 {
    queue<int> q;
public:
    MyStack_R1() {}

    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
