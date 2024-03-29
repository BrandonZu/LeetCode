//
// Created by BrandonZu on 9/21/21.
//

#include "common.h"

// Runtime 16ms(>55%) | Memory Usage 13.2MB(>46%)
class Solution_DP {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string& s: wordDict) {
            dict.insert(s);
        }

        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++) {
            for(int j = 1; j <= i; j++) {
                if(dp[j - 1] && dict.find(s.substr(j - 1, i - j + 1)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

// Runtime 8ms(>75%) | Memory Usage 7.7MB(90%)
class Solution_DP_Optimized {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<unsigned long long> dict;
        const int P = 131;
        for(string& s: wordDict) {
            unsigned long long hash = 0;
            for(char c: s)
                hash = hash * P + c;
            dict.insert(hash);
        }

        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++) {
            for(int j = 1; j <= i; j++) {
                if(dp[j - 1]) {
                    unsigned long long hash = 0;
                    for(int p = j - 1; p <= i - 1; p++)
                        hash = hash * P + s[p];
                    if(dict.find(hash) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
};

// Time Limit Exceed
class Solution_BruteForce {
    class TreeNode {
    public:
        TreeNode* children[26];
        bool isWord;
        TreeNode() {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            isWord = false;
        }
    };
    TreeNode* head;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Build Trie Tree
        head = new TreeNode;
        for(string& s: wordDict) {
            TreeNode* cur = head;
            for(char c: s) {
                int pos = c - 'a';
                if(cur->children[pos] == nullptr) {
                    cur->children[pos] = new TreeNode;
                }
                cur = cur->children[pos];
            }
            cur->isWord = true;
        }

        return recur(s, 0, head);
    }

    bool recur(const string& s, int pos, TreeNode* r) {
        if(pos == s.size() - 1) {
            return r->children[s[pos] - 'a'] && r->children[s[pos] - 'a']->isWord;
        }

        if(r->children[s[pos] - 'a'] == nullptr)
            return false;

        if(r->children[s[pos] - 'a']->isWord)
            return recur(s, pos + 1, head) || recur(s, pos + 1, r->children[s[pos] - 'a']);
        else
            return recur(s, pos + 1, r->children[s[pos] - 'a']);
    }
};

// 1st Review 11/15/21
// Runtime 4ms(>92%) | Memory Usage 9.6MB(>67%)
class Solution_R1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j >= 1; j--) {
                if(dp[j - 1] && hash.find(s.substr(j - 1, i - j + 1)) != hash.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// R .53 | M .54
class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n,false);
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                string lastStr = s.substr(j, i - j + 1);
                if(wordSet.find(lastStr) != wordSet.end() && (j == 0 || dp[j - 1])) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};