//
// Created by BrandonZu on 2021/8/11.
//

#include "common.h"

// Runtime 116ms(>92%) | Memory Usage 75.2MB(>78%)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = -prices[0], empty2 = 0, hold2 = -prices[0], end = 0;
        for(int i = 1; i < prices.size(); i++) {
            end = max(end, hold2 + prices[i]);
            hold2 = max(hold2, empty2 - prices[i]);
            empty2 = max(empty2, hold1 + prices[i]);
            hold1 = max(hold1, -prices[i]);
        }
        return max(max(empty2, end), 0);
    }
};

int main() {
    vector<int> nums = {3,5,0,3,1,4};
    Solution s;
    cout << s.maxProfit(nums);
}

