#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> myMap;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(myMap.find(target - nums[i]) != myMap.end()) {
                return {myMap[target - nums[i]], i};
            }
            myMap[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main() {
    Solution* test = new Solution;
    vector<int> nums = {2,7,11,15};
    auto result = test->twoSum(nums, 9);
    for(auto num: result)
        cout << num << ' ';
    return 0;
}
