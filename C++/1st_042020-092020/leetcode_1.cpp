#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> tmp;
        tmp.assign(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] + nums[right] == target) {
                break;
            }
            else if(nums[left] + nums[right] > target) {
                right--;
            }
            else {
                left++;
            }
        }
        if(left >= right) {
            return result;
        }
        else {
            result.push_back(find(tmp.begin(), tmp.end(), nums[left]) - tmp.begin());
            result.push_back(find(tmp.begin(), tmp.end(), nums[right]) - tmp.begin());
            return result;
        }
    }
};

int main() {
    Solution tmp;
    vector<int> nums = {3,2,8,10};
    vector<int> res = tmp.twoSum(nums, 10);
    for(auto p = res.begin(); p != res.end(); p++) {
        cout << *p << endl;
    }
}