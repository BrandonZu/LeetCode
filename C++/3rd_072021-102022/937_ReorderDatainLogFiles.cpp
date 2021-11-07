//
// Created by BrandonZu on 9/27/21.
//

#include "common.h"

// Runtime 12ms(>70%) | Memory Usage 13MB(>32%)
class Solution {
public:
    bool checkLetterLog(const string& log) {
        int i = log.find_first_of(' ');
        if(isdigit(log[i + 1]))
            return false;
        else
            return true;
    }

    static bool compLetterLog(const string& a, const string& b) {
        int aBegin = a.find_first_of(' ');
        int bBegin = b.find_first_of(' ');
        if(a.substr(aBegin + 1) == b.substr(bBegin + 1)) {
            return a.substr(0, aBegin) < b.substr(0, bBegin);
        }
        else {
            return a.substr(aBegin + 1) < b.substr(bBegin + 1);
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        int digit = logs.size() - 1;
        while(digit >= 0 && !checkLetterLog(logs[digit])) {
            digit--;
        }
        if(digit <= 0)
            return logs;

        int i = digit - 1;
        while(i >= 0) {
            if(checkLetterLog(logs[i])) {
                i--;
            }
            else {
                swap(logs[i], logs[digit]);
                digit--;
            }
        }
        digit++;
        sort(logs.begin(), logs.begin() + digit, compLetterLog);
        return logs;
    }
};

