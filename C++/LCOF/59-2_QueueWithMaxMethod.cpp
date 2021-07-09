#include <queue>

using namespace std;

class MaxQueue {
    queue<int> normalQueue;
    deque<int> maxQueue;
public:
    MaxQueue() {

    }

    int max_value() {
        if(normalQueue.empty())
            return -1;
        else
            return maxQueue.front();
    }

    void push_back(int value) {
        normalQueue.push(value);
        while(!maxQueue.empty() && maxQueue.back() < value)
            maxQueue.pop_back();
        maxQueue.push_back(value);
    }

    int pop_front() {
        if(normalQueue.empty())
            return -1;
        if(normalQueue.front() == maxQueue.front())
            maxQueue.pop_front();
        int tmp = normalQueue.front();
        normalQueue.pop();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */