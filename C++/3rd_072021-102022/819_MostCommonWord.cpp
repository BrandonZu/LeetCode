//
// Created by BrandonZu on 2021/8/19.
//

#include "common.h"

// Runtime 4ms(>90%) | Memory Usage 7.7MB(>84%)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> stringHash;
        for(auto& s: banned) {
            stringHash[s] = -1;
        }

        string word;
        for(auto c: paragraph) {
            c = tolower(c);
            if(c >= 'a' && c <= 'z') {
                word += c;
            }
            else if(!word.empty()) {
                if(stringHash[word] != -1)
                    stringHash[word]++;
                word.clear();
            }
        }

        if(!word.empty()) {
            if(stringHash[word] != -1)
                stringHash[word]++;
            word.clear();
        }
        int maxLen = 0;
        string maxStr;
        for(auto& item: stringHash) {
            if(item.second > maxLen) {
                maxLen = item.second;
                maxStr = item.first;
            }
        }
        return maxStr;
    }
};
