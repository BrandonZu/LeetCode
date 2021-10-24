//
// Created by BrandonZu on 10/21/21.
//

#include "common.h"

// Robot Bounded in Circle (LC 1041)
bool isRobotBounded(string instructions) {
    const int x_dir[4] = {-1, 0, 1, 0};
    const int y_dir[4] = {0, 1, 0, -1};
    int dir = 0;
    int x = 0, y = 0;
    for(char c: instructions) {
        if(c == 'L') {
            dir = (dir + 3) % 4;
        }
        else if(c == 'R') {
            dir = (dir + 1) % 4;
        }
        else {
            x += x_dir[dir], y += y_dir[dir];
        }
    }
    return (x == 0 && y == 0) || dir != 0;
}

// Number Game(LC 1799)
class Solution_TopDown {
public:
    int gcd(int a, int b) {
        while(a) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return b;
    }

    int maxScore(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> cache(1 << l, vector<int>(l / 2 + 1));
        function<int(int, int)> dp = [&](int mask, int k) {
            if(mask == 0)
                return 0;
            if(cache[mask][k] != 0) return cache[mask][k];
            // Choose Two Numbers
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j < l; j++) {
                    if((mask & (1 << i)) && (mask & (1 << j)) != 0) {
                        cache[mask][k] = max(cache[mask][k], k * gcd(nums[i], nums[j]) + dp(mask ^ (1 << i) ^ (1 << j), k + 1));
                    }
                }
            }
            return cache[mask][k];
        };
        return dp((1 << l) - 1, 1);
    }
};

// Shopping Options
int shoppingOptions(vector<int> jeans, vector<int> shoes, vector<int> skirts, vector<int> tops, int budget) {
    vector<int> ab, cd;
    for(int a: jeans) {
        for(int b: shoes) {
            if(a + b < budget)
                ab.push_back(a + b);
        }
    }
    sort(ab.begin(), ab.end());
    for(int c: skirts) {
        for(int d: tops) {
            if(c + d < budget)
                cd.push_back(c + d);
        }
    }
    sort(cd.begin(), cd.end());

    int res = 0;
    for(auto& i: ab) {
        int cur = upper_bound(cd.begin(), cd.end(), budget - i) - cd.begin();
        res += cur;
    }
    return res;
}

// Split String Into Unique Primes
int splitPrimes(string nums) {
    // Get all prime numbers in [2, 1000]
    unordered_set<int> primes;
    for(int i = 2; i <= 1000; i++) {
        bool flag = true;
        for(int prime: primes) {
            if(i % prime == 0) {
                flag = false;
                break;
            }
        }
        if(flag)
            primes.insert(i);
    }
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= nums.size(); i++) {
        for(int len = 1; len <= min(3, i); len++) {
            int num = stol(nums.substr(i - len, len));
            if(primes.find(num) != primes.end()) {
                dp[i] += dp[i - len];
            }
        }
    }
    return dp[nums.size()];
}

// Storage Optimization
int longestSeq(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int seq = 0;
    int last = -1;
    int max_seq = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != last + 1) {
            seq = 0;
        }
        last = arr[i];
        seq++;
        max_seq = max(max_seq, seq);
    }
    return max_seq;
}

int storage_optimization(int n, int m, vector<int> h, vector<int> v) {
    return longestSeq(h) * longestSeq(v);
}

int main() {
    string tmp = "2469";
    cout << splitPrimes(tmp) << endl;
}

