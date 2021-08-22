//
// Created by BrandonZu on 2021/8/21.
//

#include "common.h"

class TrieNode {
public:
    bool is_str;
    TrieNode* son[26];
};

// Runtime 69ms(>41%) | Memory Usage 45MB(>45%)
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for(int i = 0; i < word.size(); i++) {
            int pos = word[i] - 'a';
            if(p->son[pos] == nullptr) {
                p->son[pos] = new TrieNode();
            }
            p = p->son[pos];
        }
        p->is_str = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for(char c: word) {
            if(p->son[c - 'a'] == nullptr)
                return false;
            p = p->son[c - 'a'];
        }
        return p->is_str;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for(char c: prefix) {
            if(p->son[c - 'a'] == nullptr)
                return false;
            p = p->son[c - 'a'];
        }
        return true;
    }
};
