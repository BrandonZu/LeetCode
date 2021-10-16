//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

#include "common.h"

// Runtime 12ms(>63%) | Memory Usage 11.7MB(>12%)
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int last_word1 = -1, last_word2 = -1;
        int min_dis = wordsDict.size();
        for(int i = 0; i < wordsDict.size(); i++) {
            if(wordsDict[i] == word1) {
                if(last_word2 != -1)
                    min_dis = min(min_dis, i - last_word2);
                last_word1 = i;
            }
            else if(wordsDict[i] == word2) {
                if(last_word1 != -1)
                    min_dis = min(min_dis, i - last_word1);
                last_word2 = i;
            }
        }
        return min_dis;
    }
};
