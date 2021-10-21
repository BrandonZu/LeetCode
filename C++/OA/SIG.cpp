//
// Created by BrandonZu on 10/21/21.
//

#include "common.h"

// Camel Case
bool camelCase(vector<string> words, string name) {
    unordered_set<string> word_set;
    for(string word: words) {
        word_set.insert(word);
    }
    int pre = 0, cur = 1;
    while(cur < name.size()) {
        if(name[cur] >= 'A' && name[cur] <= 'Z') {
            string pre_word = name.substr(pre, cur - pre);
            if(word_set.find(pre_word) == word_set.end())
                return false;
            pre = cur;
        }
        cur++;
    }
    // Last word
    if(word_set.find(name.substr(pre)) == word_set.end())
        return false;
    else
        return true;
}

// Deposit


