#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string new_s = "#";
        for(char c: s)
            new_s = new_s + c + '#';
        int max_len = 0, max_pos = 0;
        int pos = 0;
        int max_right = 0;
        vector<int> rl(new_s.size(), 0);
        for(int i = 0; i < new_s.size(); i++) {
            if(i < max_right)
                rl[i] = min(rl[pos*2 - i], max_right - i);
            else
                rl[i] = 1;
            // Try to expand
            while(i - rl[i] >= 0 && i + rl[i] < new_s.size() && new_s[i - rl[i]] == new_s[i + rl[i]])
                rl[i]++;
            rl[i]--;
            if(i + rl[i] > max_right) {
                max_right = i + rl[i];
                pos = i;
            }
            if(rl[i] > max_len) {
                max_len = rl[i];
                max_pos = (i - rl[i]) / 2;
            }
        }
        return s.substr(max_pos, max_len);
    }
};