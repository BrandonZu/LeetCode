#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        unordered_map<char, int> hash;
        int l = 0, r = 0;
        hash[s[0]]++;
        int res = 0;
        while(r < s.size() - 1) {
            r++;
            hash[s[r]]++;
            while(l < r && hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};

int main() {
    Solution tmp;
    tmp.lengthOfLongestSubstring("bbb");
    return 0;
}