//
// Created by BrandonZu on 2021/7/7.
//

#include "common.h"
using namespace std;

class MinStack_1 {
    stack<int> origin_num, min_num;
public:
    /** initialize your data structure here. */
    MinStack_1() {
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

class MinStack_2 {
    stack<pair<int, int>> myStack;
public:
    /** initialize your data structure here. */
    MinStack_2() {

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

// 1st Review 09/19/2021
// Runtime 27ms(>31%) | Memory Cost 16.4MB(>34%)
class MinStack_Review {
    stack<int> s;
    stack<int> min_s;
public:
    MinStack_Review() {}

    void push(int val) {
        if(min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
        s.push(val);
    }

    void pop() {
        if(!min_s.empty() && s.top() == min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};