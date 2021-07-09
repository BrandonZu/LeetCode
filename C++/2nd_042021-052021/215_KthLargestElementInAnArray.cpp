#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return selection(nums, 0, nums.size() - 1, k);
    }

    int selection(vector<int>& nums, int left, int right, int target) {
        int pos = partition(nums, left, right);
        if(right - pos + 1 == target)
            return nums[pos];
        else if(right - pos + 1 > target)
            return selection(nums, pos + 1, right, target);
        else
            return selection(nums, left, pos - 1, target - (right - pos + 1));
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while(left < right && nums[left] < pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

