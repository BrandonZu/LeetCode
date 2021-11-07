//
// Created by BrandonZu on 9/30/21.
//

#include "common.h"

// Runtime 4ms(>87%) | Memory Usage 9.5MB(>76%)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderMap[26];
        for(int i = 0; i < order.size(); i++) {
            orderMap[order[i] - 'a'] = i;
        }
        for(int i = 0; i + 1 < words.size(); i++) {
            string a = words[i], b = words[i + 1];
            int j = 0;
            for(j = 0; j < min(a.size(), b.size()); j++) {
                if(orderMap[a[j] - 'a'] < orderMap[b[j] - 'a'])
                    break;
                else if(orderMap[a[j] - 'a'] == orderMap[b[j] - 'a'])
                    continue;
                else if(orderMap[a[j] - 'a'] > orderMap[b[j] - 'a'])
                    return false;
            }
            if(j >= min(a.size(), b.size())) {
                if(a.size() > b.size())
                    return false;
            }
        }
        return true;
    }
};

