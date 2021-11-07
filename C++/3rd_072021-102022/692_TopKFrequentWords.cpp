//
// Created by BrandonZu on 10/24/21.
//

#include "common.h"

// Runtime 10ms(>86%) | Memory Usage 13MB(>18%)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> str_map;
        for(string& word: words) {
            str_map[word]++;
        }
        vector<pair<string, int>> word_arr;
        for(auto& p: str_map) {
            word_arr.emplace_back(p);
        }

        auto cmp = [&] (pair<string, int>& a, pair<string, int>& b) {
            if(a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        make_heap(word_arr.begin(), word_arr.end(), cmp);
        vector<string> res;
        for(int i = 0; i < k; i++) {
            res.push_back(word_arr[0].first);
            pop_heap(word_arr.begin(), word_arr.end(), cmp);
            word_arr.pop_back();
        }
        return res;
    }
};
