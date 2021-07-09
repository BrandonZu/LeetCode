#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int preDiff = 0;
        int result = 1;
        for(int i = 1; i < nums.size(); i++) {
            int curDiff = nums[i] - nums[i - 1];
            if((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
