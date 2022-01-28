//
// Created by BrandonZu on 1/27/22.
//

#include "common.h"

// Runtime 10ms(>33%) | Memory Usage 7.4MB(>99%)
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = words.size();
        vector<int> posList(n, 0);
        int pos = 0;
        while(pos != string::npos) {
            char c = s[pos];
            int j = s.find_first_not_of(c, pos);
            int len = j == string::npos ? s.size() - pos : j - pos;
            pos = j;

            for(int i = 0; i < n; i++) {
                if(posList[i] == INT_MIN)
                    continue;
                if(posList[i] == string::npos || words[i][posList[i]] != c) {
                    posList[i] = INT_MIN;
                    continue;
                }
                int next = words[i].find_first_not_of(c, posList[i]);
                int cur_len = next == string::npos ? words[i].size() - posList[i] : next - posList[i];
                if(cur_len > len || (cur_len < len && len < 3)) {
                    posList[i] = INT_MIN;
                    continue;
                }
                else {
                    posList[i] = next;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(posList[i] == string::npos)
                cnt++;
        }
        return cnt;
    }
};

