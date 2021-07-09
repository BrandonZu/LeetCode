#include<algorithm>
#include<vector>
using namespace std;
// 朴素DP
// Time Complexity:O(n); Space Complexity:O(n)
class Solution_1 {
public:
    int trap(vector<int>& height) {
        int* left_top = new int[height.size()];
        int* right_top = new int[height.size()];
        int left_top_tmp = 0;
        for(int i = 0; i < height.size(); i++) {
            left_top[i] = left_top_tmp;
            if(height[i] > left_top_tmp)
                left_top_tmp = height[i];
        }
        int right_top_tmp = 0;
        for(int i = height.size()-1; i >= 0; i--) {
            right_top[i] = right_top_tmp;
            if(height[i] > right_top_tmp)
                right_top_tmp = height[i];
        }
        int count = 0;
        for(int i = 0; i < height.size(); i++) {
            if(min(left_top[i], right_top[i]) > height[i])
                count += min(left_top[i], right_top[i]) - height[i];
        }
        return count;
    }
};

// 双指针
// Time Complexity:O(n); Space Complexity:O(1)


// 单调栈
// Time Complexity:O(n); Space Complexity:O(n)