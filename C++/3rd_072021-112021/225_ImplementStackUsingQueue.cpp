//
// Created by BrandonZu on 2021/7/8.
//

#include "stack"
#include "queue"
using namespace std;

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
