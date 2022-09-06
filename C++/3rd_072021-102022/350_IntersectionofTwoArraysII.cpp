//
// Created by BrandonZu on 9/5/22.
//

#include "common.h"

// R .100 | M .52
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Map;
        vector<int> res;
        for(int num : nums1) {
            nums1Map[num]++;
        }
        for(int num : nums2) {
            if(nums1Map.find(num) != nums1Map.end()) {
                res.push_back(num);
                nums1Map[num]--;
                if(nums1Map[num] == 0) {
                    nums1Map.erase(num);
                }
            }
        }
        return res;
    }
};
