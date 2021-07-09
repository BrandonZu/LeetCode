#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        selection(nums, 0, nums.size() - 1);
        return nums;
    }

    void selection(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return;
        }

        int pos = partition(nums, left, right);

        selection(nums, left, pos - 1);
        selection(nums, pos + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        swap(nums[(left + right) / 2], nums[left]);
        int pivot = nums[left];
        int l = left, r = right;
        while(l < r) {
            while(l < r && nums[r] >= pivot) {
                r--;
            }
            nums[l] = nums[r];
            while(l < r && nums[l] < pivot) {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

    int partition2(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left;
        for(int j = i + 1; j <= right; j++) {
            if(nums[j] >= pivot)
                continue;
            else {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[i]);
        return i;
    }
};

