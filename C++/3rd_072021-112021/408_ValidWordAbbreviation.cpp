//
// Created by BrandonZu on 11/4/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>70.1%)
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size()) {
            if(isalpha(abbr[j])) {
                if(word[i] != abbr[j])
                    return false;
                i++, j++;
            }
            else {
                int tmp = 0;
                while(j < abbr.size() && isdigit(abbr[j])) {
                    tmp *= 10;
                    tmp += abbr[j] - '0';
                    if(i + tmp > word.size() || tmp == 0) return false;
                    j++;
                }
                i += tmp;
            }
        }
        return i == word.size() && j == abbr.size();
    }
};

int main() {
    Solution s;
    string word = "internationalization";
    string abbr = "i12iz4n";
    cout << s.validWordAbbreviation(word, abbr) << endl;
}
