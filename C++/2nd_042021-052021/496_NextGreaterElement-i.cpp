#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        stack<int> stk;
        unordered_map<int, int> map;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!stk.empty() && stk.top() < nums2[i]) {
                stk.pop();
            }
            map[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        for(int cur : nums1) {
            result.push_back(map[cur]);
        }
        return result;
    }
};
