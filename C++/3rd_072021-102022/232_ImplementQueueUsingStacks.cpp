//
// Created by BrandonZu on 2021/7/10.
//

#include"stack"
using namespace std;

class MyQueue {
    stack<int> s_in, s_out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s_out.empty()) {
            while(!s_in.empty()) {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        int result = s_out.top();
        s_out.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        if(s_out.empty()) {
            while(!s_in.empty()) {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        return s_out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s_in.empty() && s_out.empty();
    }
};
