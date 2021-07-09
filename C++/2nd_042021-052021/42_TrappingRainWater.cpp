#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> stk;
        for(int pos = 0; pos < height.size(); pos ++) {
            while(!stk.empty() && height[pos] > height[stk.top()]) {
                int cur = stk.top();
                stk.pop();
                if(stk.empty())
                    break;
                int left = stk.top();
                result += (pos - left - 1) * (min(height[left], height[pos]) - height[cur]);
            }
            stk.push(pos);
        }
        return result;
    }
};

int main() {
    vector<int> test = {};
    Solution ss;
    cout << ss.trap(test) << endl;
    return 0;
}