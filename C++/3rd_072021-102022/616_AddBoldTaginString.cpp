//
// Created by BrandonZu on 11/27/21.
//

#include "common.h"



class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> intervals;
        for(string& word: words) {
            int pos = s.find(word);
            if(pos != string::npos)
                intervals.push_back({pos, pos + word.size() - 1});
        }
        sort(intervals.begin(), intervals.end());
        string res;
        int pos = 0;
        int prev = 0;
        while(pos < intervals.size() && prev < s.size()) {
            int begin = intervals[pos].first, end = intervals[pos].second;
            int j;
            for(j = pos + 1; j < intervals.size(); j++) {
                if(intervals[j].first <= end + 1) {
                    end = max(end, intervals[j].second);
                }
                else {
                    break;
                }
            }
            pos = j;
            res += s.substr(prev, begin - prev);
            res += "<b>" + s.substr(begin, end - begin + 1) + "</b>";
            prev = end + 1;
        }
        if(prev < s.size())
            res += s.substr(prev);
        return res;
    }
};
