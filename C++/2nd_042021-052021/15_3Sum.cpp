#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if(size < 3)
            return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            // Using Two Pointers
            int left = i + 1, right = size - 1;
            while(left < right) {
                if(nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                }
                else if(nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    while(left < right && nums[right + 1] == nums[right])
                        right--;
                }
            }
        }
        return result;
    }
};

