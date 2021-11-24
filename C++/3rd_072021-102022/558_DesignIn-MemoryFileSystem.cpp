//
// Created by BrandonZu on 11/23/21.
//

#include "common.h"

// Runtime 56ms(>5%) | Memory Usage 15.8MB(>21%)
class FileSystem {
    class Node {
    public:
        string content;
        unordered_map<string, Node*> children;
        bool isFile;

        Node() {
            isFile = false;
        }
    };

    vector<string> stringSplit(const string& str, const string& deli) {
        vector<string> tokens;

        string::size_type start = 0, end = 0;
        while((end = str.find(deli, start)) != string::npos) {
            tokens.push_back(str.substr(start, end - start));

            start = end + deli.size();
        }
        if(start < str.size())
            tokens.push_back(str.substr(start));
        return tokens;
    }

    Node* root;

public:

    FileSystem() {
        root = new Node();
    }

    vector<string> ls(string path) {
        vector<string> strs = stringSplit(path, "/");
        Node* cur = root;
        for(int i = 1; i < strs.size(); i++) {
            cur = cur->children[strs[i]];
        }

        if(cur->isFile) {
            return {strs.back()};
        }

        vector<string> res;
        for(auto& p: cur->children) {
            res.push_back(p.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path) {
        vector<string> strs = stringSplit(path, "/");
        Node* cur = root;
        for(int i = 1; i < strs.size(); i++) {
            if(cur->children.find(strs[i]) == cur->children.end()) {
                cur->children[strs[i]] = new Node();
            }
            cur = cur->children[strs[i]];
        }
    }

    void addContentToFile(string filePath, string content) {
        vector<string> strs = stringSplit(filePath, "/");
        Node* cur = root;
        for(int i = 1; i < strs.size(); i++) {
            if(cur->children.find(strs[i]) == cur->children.end()) {
                cur->children[strs[i]] = new Node();
            }
            cur = cur->children[strs[i]];
        }
        cur->isFile = true;
        cur->content += content;
    }

    string readContentFromFile(string filePath) {
        vector<string> strs = stringSplit(filePath, "/");
        Node* cur = root;
        for(int i = 1; i < strs.size(); i++) {
            cur = cur->children[strs[i]];
        }
        return cur->content;
    }
};
