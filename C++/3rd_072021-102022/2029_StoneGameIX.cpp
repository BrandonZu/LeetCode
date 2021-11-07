//
// Created by BrandonZu on 10/3/21.
//

#include "common.h"

// Runtime 172ms(>83%) | Memory Usage 127MB(>95%)
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for(int s: stones)
            cnt[s % 3]++;
        bool flip = (cnt[0] % 2 != 0);

        if(cnt[1] == 0) {
            return cnt[2] >= 3 && flip;
        }
        if(cnt[2] == 0) {
            return cnt[1] >= 3 && flip;
        }

        return abs(cnt[1] - cnt[2]) > 2 || !flip;
    }
};

class Solution_Simulation {
public:
    bool get(vector<int> mod, int n, int k)
    {
        if (mod[k] < 1)
            return false;
        mod[k]--;
        int sum = k;
        for (int i = 1; i < n; i++)
        {
            if (mod[1] && (sum + 1) % 3 != 0)
                mod[1]--, sum += 1;
            else if (mod[2] && (sum + 2) % 3 != 0)
                mod[2]--, sum += 2;
            else if (mod[0] > 0 && (sum) % 3 != 0)
                mod[0]--;
            else
                return i & 1;
        }
        return false;
    }

    bool stoneGameIX(vector<int> &v)
    {
        vector<int> mod(3);
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            mod[v[i] % 3]++;
        }
        return get(mod, n, 2) || get(mod, n, 1);
    }
};