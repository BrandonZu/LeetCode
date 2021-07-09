#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxSum = nums[0];
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
            curSum = curSum < 0 ? 0 : curSum;
        }
        return maxSum;
    }
};

