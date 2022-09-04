//
// Created by BrandonZu on 9/3/22.
//

#include "common.h"

class ArrayReader {
public:
    int get(int index) const;
};

// R .81 | M .42
class Solution {
public:
    const int INVALID = INT32_MAX;
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = INT32_MAX;
        while(l <= r) {
            long mid = (l + r) / 2;
            int res = reader.get(mid);
            if(res == target) {
                return mid;
            }
            else if(res == INVALID || res > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
