#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int cnt;
    vector<int> tmp;
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        cnt = 0;
        tmp = vector<int>(nums.size());
        merge(nums, 0, nums.size() - 1);
        return cnt;
    }

    void merge(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        merge(nums, left, mid);
        merge(nums, mid + 1, right);
        int l = left, r = mid + 1, pos = l;
        while(l <= mid && r <= right) {
            if(nums[l] <= nums[r]) {
                tmp[pos++] = nums[l++];
            }
            else {
                cnt += mid - l + 1;
                tmp[pos++] = nums[r++];
            }
        }
        while(l <= mid) {
            tmp[pos++] = nums[l++];
        }
        while(r <= right) {
            tmp[pos++] = nums[r++];
        }
        for(int i = left; i <= right; i++) {
            nums[i] = tmp[i];
            tmp[i] = 0;
        }
    }
};
