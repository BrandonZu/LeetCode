//
// Created by BrandonZu on 2/10/22.
//

#include "common.h"

// Runtime 75ms(>41%) | Memory Usage 23.5MB(>98%)
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for(string& s: strs) {
            res += s;
            res += "@";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int pos = 0;
        while(pos != string::npos && pos < s.size()) {
            int next = s.find('@', pos);
            ans.push_back(s.substr(pos, next - pos));
            pos = next + 1;
        }
        return ans;
    }
};
