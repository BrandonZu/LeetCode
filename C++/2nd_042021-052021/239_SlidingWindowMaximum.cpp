#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            while(!window.empty() && nums[window.back()] <= cur) {
                window.pop_back();
            }
            window.push_back(i);
            if(window.front() < i - k + 1)
                window.pop_front();
            if(i >= k - 1)
                result.push_back(nums[window.front()]);
        }

        return result;
    }
};

int main() {
    vector<int> test = {7,2,4};
    int k = 2;
    Solution ss;
    vector<int> result = ss.maxSlidingWindow(test, 2);

}