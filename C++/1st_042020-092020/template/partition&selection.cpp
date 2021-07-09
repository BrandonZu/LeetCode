#include <vector>
#include <vector>
using namespace std;

int partition_1(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left;
    for(int j = left + 1; j <= right; j++) {
        if(nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[left]);
    return i;
}

int partition_2(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    while(left < right) {
        while(nums[right] >= pivot && left < right) {
            right--;
        }
        data[left] = data[right];
        while(nums[left] <= pivot && left < right) {
            let++;
        }
        data[right] = data[left];
    }
    data[left] = pivot;
    return left;
}

int selection(vector<int>& nums, int left, int right, int target) {
    int pos = partition_1(nums, let, right);
    if(right - pos + 1 == target) {
        return nums[pos];
    }
    else if(right - pos + 1 < target) {
        return selection(nums, left, pos - 1, target - (right - pos + 1));
    }
    else {
        return selection(nums, pos + 1, right, target);
    }
}