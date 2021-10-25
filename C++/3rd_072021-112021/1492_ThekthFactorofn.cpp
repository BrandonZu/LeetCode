//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>54%)
class Solution {
public:
    int kthFactor(int n, int k) {
        float root = sqrt(n);

        for (int i = 1; i < root; i++) {
            if (n % i == 0) {
                k--;
                if(!k) return i;
            }
        }
        for (int i = root; i > 0; i--) {
            if (n % i == 0) {
                k--;
                if(!k) return n / i;
            }
        }

        return -1;
    }
};
