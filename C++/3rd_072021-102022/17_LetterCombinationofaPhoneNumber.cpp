//
// Created by BrandonZu on 2021/7/31.
//
#include "common.h"

// Runtime 0ms (>100%) | Memory Usage 6.5 MB(>86.5%)
class Solution {
    const string numToChar[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string path;
public:
    void backtrack(const string& digits, int pos) {
        if(pos >= digits.size()) {
            result.push_back(path);
            return;
        }
        for(char c : numToChar[digits[pos] - '0']) {
            path.push_back(c);
            backtrack(digits, pos + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // Notice: when digits is empty, function should return {}, not {""}!
        if(digits.empty()) return result;

        backtrack(digits, 0);

        return result;
    }
};

// R .100 | M .55
class Solution2 {
    const string numToChar[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        helper(digits, 0);
        return res;
    }

    void helper(const string& digits, int pos) {
        if(pos >= digits.size()) {
            res.push_back(path);
            return;
        }
        for(char c : numToChar[digits[pos] - '0']) {
            path.push_back(c);
            helper(digits, pos + 1);
            path.pop_back();
        }
    }
};