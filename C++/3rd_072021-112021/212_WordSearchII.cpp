//
// Created by BrandonZu on 2021/8/21.
//

#include "common.h"

// Runtime 564ms(>48%) | Memory Usage 9.5MB(>27%)
class Solution {
    class TrieNode {
    public:
        int id;
        TrieNode* adj[26];
        TrieNode() {
            id = -1;
            for(int i = 0; i < 26; i++)
                adj[i] = nullptr;
        }
    };
    TrieNode* r;
    vector<vector<char>> board;
    vector<string> words;
    vector<string> res;
    unordered_set<string> hashSet;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    void dfs(int x, int y, TrieNode* p) {
        if(!p)
            return;
        if(p->id != -1) {
            if(hashSet.find(words[p->id]) == hashSet.end()) {
                res.push_back(words[p->id]);
                hashSet.insert(words[p->id]);
            }
        }

        char tmp = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && x + dx[i] < board.size() && y + dy[i] >= 0 && y + dy[i] < board[0].size() && board[x + dx[i]][y + dy[i]] != '*') {
                dfs(x + dx[i], y + dy[i], p->adj[board[x + dx[i]][y + dy[i]] - 'a']);
            }
        }
        board[x][y] = tmp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = new TrieNode();
        this->board = board;
        this->words = words;
        // Build Trie Tree
        for(int i = 0; i < words.size(); i++) {
            TrieNode* p = r;
            for(char c: words[i]) {
                if(!p->adj[c - 'a'])
                    p->adj[c - 'a'] = new TrieNode();
                p = p->adj[c - 'a'];
            }
            p->id = i;
        }
        // Search Words
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(i, j, r->adj[board[i][j] - 'a']);
            }
        }
        return res;
    }
};

// Fail: TLE
class Solution_BuildTrieFromBoard {
    class TrieNode {
    public:
        bool is_str;
        TrieNode* adj[26];
    };
    TrieNode* root;
    vector<vector<char>> board;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:

    void buildTrie(int x, int y, TrieNode* r) {
        // Create Current Node
        int pos = board[x][y] - 'a';
        if(r->adj[pos] == nullptr) {
            r->adj[pos] = new TrieNode();
        }
        r->adj[pos]->is_str = true;

        char tmp = board[x][y];
        board[x][y] = '*';
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && x + dx[i] < board.size() && y + dy[i] >= 0 && y + dy[i] < board[0].size() && board[x + dx[i]][y + dy[i]] != '*') {
                buildTrie(x + dx[i], y + dy[i], r->adj[pos]);
            }
        }
        board[x][y] = tmp;
    }

    bool queryWord(const string& word) {
        TrieNode* p = root;
        for(char c: word) {
            if(p->adj[c - 'a'] == nullptr)
                return false;
            else
                p = p->adj[c - 'a'];
        }
        return p && p->is_str;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        this->board = board;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                buildTrie(i, j, root);
            }
        }

        vector<string> res;
        for(string& word: words) {
            if(queryWord(word))
                res.push_back(word);
        }
        return res;
    }
};