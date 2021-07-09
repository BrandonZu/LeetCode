#include <stack>
#include <iostream>

using namespace std;

class MinStack {
    stack<int> normalStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        normalStack.push(x);
        if(minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if(normalStack.top() == minStack.top())
            minStack.pop();
        normalStack.pop();
    }

    int top() {
        return normalStack.top();
    }

    int min() {
        return minStack.top();
    }
};
