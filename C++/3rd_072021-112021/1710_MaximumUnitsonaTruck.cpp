//
// Created by BrandonZu on 10/23/21.
//

#include "common.h"

// Runtime 45ms(>62%) | Memory Usage 15.8MB(>100%)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        int count = 0;
        for(int i = 0; i < boxTypes.size() && truckSize; i++) {
            int cur = min(truckSize, boxTypes[i][0]);
            truckSize -= cur;
            count += cur * boxTypes[i][1];
        }
        return count;
    }
};

// Runtime 47ms(>61%) | Memory Usage 16MB(>55%)
class Solution2 {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int buckets[1001] = {};
        for(auto& box: boxTypes) {
            buckets[box[1]] += box[0];
        }
        int res = 0;
        for(int i = 1000; i >= 1 && truckSize; i--) {
            if(buckets[i]) {
                int cur = min(truckSize, buckets[i]);
                truckSize -= cur;
                res += cur * i;
            }
        }
        return res;
    }
};
