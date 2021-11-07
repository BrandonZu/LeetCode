//
// Created by BrandonZu on 2021/8/19.
//

#include "common.h"

// Runtime 24ms(>85%) | Memory Usage 10.6MB(>89%)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> charMap(26, make_pair(0, -1));
        for(int i = 0; i < s.size(); i++) {
            charMap[s[i] - 'a'].first++;
            if(charMap[s[i] - 'a'].second == -1)
                charMap[s[i] - 'a'].second = i;
        }
        int minPos = s.size();
        for(auto& p: charMap) {
            if(p.first == 1) {
                minPos = min(minPos, p.second);
            }
        }
        return minPos == s.size() ? -1 : minPos;
    }
};

// Runtime 20ms(>96%) | Memory Usage 11MB(>91%)
class Solution_R1 {
public:
    int firstUniqChar(string s) {
        int freq[26] = {};
        for(char c: s) {
            freq[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++ {
            if(freq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
