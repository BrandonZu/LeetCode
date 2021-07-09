#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while(left < right) {
            while(nums[right] >= pivot && left < right)
                right--;
            nums[left] = nums[right];
            while(nums[left] <= pivot && left < right)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    int selection(vector<int>& nums, int left, int right, int target) {
        int pos = partition(nums, left, right);
        if(right - pos + 1 == target)
            return nums[pos];
        else if(right - pos + 1 < target)
            return selection(nums, left, pos - 1, target - (right - pos + 1));
        else
            return selection(nums, pos + 1, right, target);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return selection(nums, 0, nums.size()-1, k);
    }
};

int main() {
    Solution tmp;
    vector<int> tmp_num = {2, 1};
    tmp.findKthLargest(tmp_num, 2);
}