//
// Created by BrandonZu on 10/21/21.
//

#include "common.h"

// Runtime 4ms(>85%) | Memory Usage 9.2MB(>39%)
class Solution {
    vector<bool> used;
public:
    bool dfs(vector<int>& nums, int num_pos, int cur_sum, int cur_group, int k, int target_sum) {
        // All the groups satisfies the requirement
        if(cur_group == k)
            return true;
        // Search Next Group
        if(cur_sum == target_sum)
            return dfs(nums, 0, 0, cur_group + 1, k, target_sum);
        for(int i = num_pos; i < nums.size(); i++) {
            if(used[i]) continue;
            if(cur_sum + nums[i] <= target_sum) {
                used[i] = true;
                if(dfs(nums, i + 1, cur_sum + nums[i], cur_group, k, target_sum))
                    return true;
                used[i] = false;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
            if(cur_sum == 0 || cur_sum + nums[i] == target_sum)
                return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        // Corner Cases
        if(k == 1) return true;
        if(k > N) return false;
        int total_sum = 0;
        for(int num: nums)
            total_sum += num;
        if(total_sum % k != 0)
            return false;
        int group_sum = total_sum / k;
        sort(nums.begin(), nums.end());
        used.resize(N, false);
        return dfs(nums, 0, 0, 0, k, group_sum);
    }
};


