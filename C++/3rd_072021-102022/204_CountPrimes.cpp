//
// Created by BrandonZu on 1/20/22.
//

#include "common.h"

// Runtime 612ms(>10%) | Memory Usage 10.2MB(>70%)
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i < n; i++) {
            if(prime[i]) {
                for(int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};
