#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int min_len = strs[0].size();
        for(auto& p : strs)
            min_len = p.size() < min_len ? p.size() : min_len;
        for(int i = 0; i < min_len; i++) {
            char cur = strs[0][i];
            for(auto& str : strs)
                if(str[i] != cur) {
                    if (i == 0)
                        return "";
                    else
                        return strs[0].substr(0, i);
                }
        }
        return strs[0].substr(0, min_len);
    }
};
