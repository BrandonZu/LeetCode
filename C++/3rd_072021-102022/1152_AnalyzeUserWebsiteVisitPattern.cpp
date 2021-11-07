//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<pair<int, int>> visitList;
        for(int i = 0; i < username.size(); i++) {
            visitList.emplace_back(timestamp[i], i);
        }
        sort(visitList.begin(), visitList.end());
        unordered_map<string, vector<string>> userVisitList;
        for(auto& p: visitList) {
            int index = p.second;
            userVisitList[username[index]].push_back(website[index]);
        }
        unordered_map<string, int> patternCnt;
        for(auto& p: userVisitList) {
            auto& userVisit = p.second;
            if(userVisit.size() < 3) continue;
            for(int i = 0; i < userVisit.size(); i++) {
                for(int j = i + 1; j < userVisit.size(); j++) {
                    for(int k = j + 1; k < userVisit.size(); k++) {
                        patternCnt[userVisit[i] + ',' + userVisit[j] + ',' + userVisit[k]]++;
                    }
                }
            }
        }
        int maxCnt = 0;
        for(auto& p: patternCnt) {
            maxCnt = max(maxCnt, p.second);
        }
        string resStr;
        for(auto& p: patternCnt) {
            if(p.second == maxCnt && (resStr.empty() || p.first < resStr))
                resStr = p.first;
        }
        resStr += ',';
        vector<string> res;
        int pos = 0;
        while(pos != string::npos && pos < resStr.size()) {
            int end = resStr.find_first_of(',', pos);
            res.push_back(resStr.substr(pos, end - pos));
            pos = end + 1;
        }
        return res;
    }
};

