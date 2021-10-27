//
// Created by BrandonZu on 2021/8/14.
//

#include "common.h"

// Runtime 31ms(>13%) | Memory Usage 17.8MB(>61%)
class Solution {
public:
    inline void forward(vector<int>& ratings, vector<int>& candies, int pos) {
        for(int i = pos + 1; i < ratings.size() && ratings[i] > ratings[i - 1]; i++) {
            if(candies[i] != -1) {
                candies[i] = max(candies[i], candies[i - 1] + 1);
                break;
            }

            candies[i] = candies[i - 1] + 1;
        }
    }

    inline void backward(vector<int>& ratings, vector<int>& candies, int pos) {
        for(int i = pos - 1; i >= 0 && ratings[i] > ratings[i + 1]; i--) {
            if(candies[i] != -1) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
                break;
            }

            candies[i] = candies[i + 1] + 1;
        }
    }

    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), -1);

        for(int i = 0; i < candies.size(); i++) {
            bool flag = true;
            if(i - 1 >= 0 && ratings[i - 1] < ratings[i])
                flag = false;
            if(i + 1 < ratings.size() && ratings[i] > ratings[i + 1])
                flag = false;
            if(flag) {
                candies[i] = 1;
                forward(ratings, candies, i);
                backward(ratings, candies, i);
            }
        }

        int res = 0;
        for(int c: candies)
            res += c;
        return res;
    }
};

// Runtime 20ms(>70%) | Memory Usage 19.4MB(>9%)
class Solution_DP_Memo {
public:
    // Memoization
    int dp_memo(vector<int>& ratings, vector<int>& candies, int pos) {
        if(candies[pos] != -1)
            return candies[pos];
        candies[pos] = 1;
        if(pos + 1 < candies.size() && ratings[pos] > ratings[pos + 1])
            candies[pos] = max(candies[pos], dp_memo(ratings, candies, pos + 1) + 1);
        if(pos - 1 >= 0 && ratings[pos] > ratings[pos - 1])
            candies[pos] = max(candies[pos], dp_memo(ratings, candies, pos - 1) + 1);
        return candies[pos];
    }

    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), -1);
        int res = 0;
        for(int i = 0; i < candies.size(); i++)
            res += dp_memo(ratings, candies, i);
        return res;
    }
};

// Runtime 16ms(>92%) | Memory Usage 17.8MB(>37%)
class Solution_DP_Tabu {
public:
    // Tabulation
    void dp_tabu(vector<int>& ratings, vector<int>& candies) {
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        dp_tabu(ratings, candies);
        int res = 0;
        for(int c: candies)
            res += c;
        return res;
    }
};
