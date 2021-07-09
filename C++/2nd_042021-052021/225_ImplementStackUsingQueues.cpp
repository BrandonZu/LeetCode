#include <queue>
using namespace std;

class MyStack {
    queue<int> myQueue;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = myQueue.size();
        myQueue.push(x);
        for(int i = 0; i < size; i++) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = myQueue.front();
        myQueue.pop();
        return tmp;
    }

    /** Get the top element. */
    int top() {
        return myQueue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
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