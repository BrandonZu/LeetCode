#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> mock;
        auto push = pushed.begin();
        auto pop = popped.begin();
        while(push != pushed.end() && pop != popped.end()) {
            mock.push(*push);
            push++;
            while(!mock.empty() && pop != popped.end() && mock.top() == *pop) {
                mock.pop();
                pop++;
            }
        }
        return push == pushed.end() && pop == popped.end();
    }
};

