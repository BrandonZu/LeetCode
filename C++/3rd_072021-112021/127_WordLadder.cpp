//
// Created by BrandonZu on 9/22/21.
//

#include "common.h"

// Runtime 108ms(>75%) | Memory Cost 16MB(>41%)
class Solution {
public:
    unordered_map<string, int> dist;
    queue<string> q;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(const string& word: wordList)
            dict.insert(word);
        dist[beginWord] = 0;
        q.push(beginWord);
        while(!q.empty()) {
            string cur = q.front();
            if(cur == endWord)
                break;
            q.pop();

            for(int i = 0; i < cur.size(); i++) {
                string tmp = cur;
                for(char j = 'a'; j <= 'z'; j++) {
                    tmp[i] = j;
                    if(dict.find(tmp) != dict.end() && dist.find(tmp) == dist.end()) {
                        dist[tmp] = dist[cur] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        if(dist.find(endWord) == dist.end())
            return 0;
        else
            return dist[endWord] + 1;
    }
};

