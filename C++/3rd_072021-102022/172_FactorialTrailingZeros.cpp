//
// Created by BrandonZu on 1/18/22.
//

// Runtime 6ms(>12%) | Memory Usage 6MB(>27%)
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n) {
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
