//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"

// Runtime 28ms(>98%) | Memory Usage 31MB(>100%)
class Solution_Optimzed {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - k;
        while(l < r) {
            int mid = l + r >> 1;
            if(abs(arr[mid] - x) <= abs(arr[mid + k] - x)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

// Runtime 32ms(>94%) | Memory Usage 32MB(>38%)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> front, back;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(arr[mid] >= x) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        r = l, l = l - 1;
        while(l >= 0 && r < n && k) {
            if(arr[r] - x < x - arr[l]) {
                back.push_back(arr[r++]);
                k--;
            }
            else {
                front.push_back(arr[l--]);
                k--;
            }
        }
        while(r < n && k) {
            back.push_back(arr[r++]);
            k--;
        }
        while(l >= 0 && k) {
            front.push_back(arr[l--]);
            k--;
        }
        reverse(front.begin(), front.end());
        front.insert(front.end(), back.begin(), back.end());
        return front;
    }
};

