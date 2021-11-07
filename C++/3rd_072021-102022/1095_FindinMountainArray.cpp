//
// Created by BrandonZu on 2021/7/18.
//

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        if(len == 1)
            return mountainArr.get(0) == target ? 0 : -1;

        int l = 1, r = len - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(mountainArr.get(mid - 1) < mountainArr.get(mid))
                l = mid;
            else
                r = mid - 1;
        }
        int peak = l;
        // Left Part
        l = 0, r = peak;
        while(l <= r) {
            int mid = l + r >> 1;
            int midVal = mountainArr.get(mid);
            if(midVal == target)
                return mid;
            else if(midVal > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        // Right Part
        l = peak, r = len - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            int midVal = mountainArr.get(mid);
            if(midVal == target)
                return mid;
            else if(midVal > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};