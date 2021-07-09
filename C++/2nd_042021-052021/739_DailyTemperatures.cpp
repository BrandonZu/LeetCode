#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> result(T.size());
        for(int i = T.size() - 1; i >= 0; i--) {
            while(!stk.empty() && T[i] >= T[stk.top()])
                stk.pop();
            result[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return result;
    }
};
