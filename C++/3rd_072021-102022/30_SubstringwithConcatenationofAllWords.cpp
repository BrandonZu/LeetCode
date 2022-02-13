//
// Created by BrandonZu on 2/11/22.
//

#include "common.h"

// Runtime 128ms(>67.18%) | Memory Usage 42.3MB(>30%)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty())
            return result;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> word_cnt;
        for(string& word: words) {
            word_cnt[word]++;
        }

        for(int i = 0; i < w; i++) {
            unordered_map<string, int> wd;
            int cnt = 0;
            int l = i, r = l;
            while(r <= n) {
                // Push one element
                auto tmp = s.substr(r, w);
                wd[tmp]++;
                if(wd[tmp] <= word_cnt[tmp]) {
                    cnt++;
                }
                r += w;
                // Pop one element if needed
                if(r - l > m * w) {
                    tmp = s.substr(l, w);
                    wd[tmp]--;
                    if(wd[tmp] < word_cnt[tmp]) {
                        cnt--;
                    }
                    l += w;
                }
                if(cnt == m) {
                    result.push_back(l);
                }
            }
        }
        return result;
    }
};
