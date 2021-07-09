#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> result;
        if(nums.empty())
            return {};
        window.push_back(0);
        if(k == 1)
            result.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            // 删除头部
            if(window.front() < i - k + 1)
                window.pop_front();
            // 清除无用
            while(!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();
            // 加入尾部
            window.push_back(i);
            // 取得最大
            if(i >= k-1)
                result.push_back(nums[window.front()]);
        }
        return result;
    }
};

