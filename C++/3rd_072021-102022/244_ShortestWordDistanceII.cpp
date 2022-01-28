//
// Created by BrandonZu on 1/27/22.
//

#include "common.h"

// Runtime 70ms(>17%) | Memory Usage 19.4MB(>63%)
class WordDistance {
public:
    unordered_map<string, vector<int>> wordsPos;

    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            wordsPos[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int ret = INT_MAX;
        int p1 = 0, p2 = 0;
        while(p1 < wordsPos[word1].size() && p2 < wordsPos[word2].size()) {
            ret = min(ret, abs(wordsPos[word1][p1] - wordsPos[word2][p2]));
            if(wordsPos[word1][p1] > wordsPos[word2][p2]) {
                p2++;
            }
            else {
                p1++;
            }
        }
        return ret;
    }
};

