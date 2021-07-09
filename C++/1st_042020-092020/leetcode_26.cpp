#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int count = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[count]) {
                count++;
                nums[count] = nums[i];
            }
        }
        return count + 1;
    }
};

int main() {
    vector<int> tmp = {1,1,2};
    Solution test;
    test.removeDuplicates(tmp);
    return 0;
}