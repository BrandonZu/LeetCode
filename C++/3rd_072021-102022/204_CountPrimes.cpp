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

// Runtime 492ms(>18%) | Memory Usage 12.1MB(>21%)
int primes[(int)1e6];
bool notPrime[5 * (int)1e6];
class Solution_2 {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        int cnt = 0;
        for(int i = 2; i <= n - 1; i++) {
            if(!notPrime[i])
                primes[cnt++] = i;
            for(int j = 0; primes[j] <= (n - 1) / i; j++) {
                notPrime[primes[j] * i] = true;
                if(i % primes[j] == 0)
                    break;
            }
        }
        return cnt;
    }
};
