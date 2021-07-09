#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(auto p = nums.begin(); p != nums.end(); p++) {
            if(map.find(target - *p) != map.end()) {
                return {map[target - *p], (int)(p - nums.begin())};
            }
            else {
                map[*p] = p - nums.begin();
            }
        }
        return {0, 0};
    }
};
