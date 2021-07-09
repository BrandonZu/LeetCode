#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1;
        int minNum = nums[0];
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[l] < nums[r]) {
                r = mid;
            }
            else {
                if(nums[mid] >= nums[l]) {
                    l = mid + 1;
                }
                else if(nums[mid] < nums[r]) {
                    r = mid;
                }
            }
        }
        return nums[l];
    }
};

