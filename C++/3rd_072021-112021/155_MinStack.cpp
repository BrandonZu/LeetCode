//
// Created by BrandonZu on 2021/7/7.
//

#include "stack"
using namespace std;

class MinStack_1 {
    stack<int> origin_num, min_num;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int val) {
        if(origin_num.empty() || val <= min_num.top()) {
            origin_num.push(val);
            min_num.push(val);
        }
        else {
            origin_num.push(val);
        }
    }

    void pop() {
        if(origin_num.top() == min_num.top())
            min_num.pop();
        origin_num.pop();
    }

    int top() {
        return origin_num.top();
    }

    int getMin() {
        return min_num.top();
    }
};

class MinStack {
    stack<pair<int, int>> myStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if(myStack.empty())
            myStack.push({val, val});
        else {
            int curMin = myStack.top().second;
            myStack.push({val, min(curMin, val)});
        }
    }

    void pop() {
        myStack.pop();
    }

    int top() {
        return myStack.top().first;
    }

    int getMin() {
        return myStack.top().second;
    }
};