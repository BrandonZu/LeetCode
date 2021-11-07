//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

// Runtime 16ms(>75%) | Memory Usage 20MB(>67%)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1)
                continue;
            if((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                n--;
                flowerbed[i] = 1;
                if(n <= 0)
                    return true;
            }
        }
        return n <= 0;
    }
};
