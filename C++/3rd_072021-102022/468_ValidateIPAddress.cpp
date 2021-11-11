//
// Created by BrandonZu on 11/10/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6.3MB(>83%)
class Solution {
public:
    vector<string> split(string& str, char deli) {
        vector<string> tokens;

        size_t start = 0, end = 0;
        while((end = str.find(deli, start)) != string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }

    string validIPAddress(string queryIP) {
        return validIPv4(queryIP) ? "IPv4" : (validIPv6(queryIP) ? "IPv6" : "Neither");
    }

    bool validIPv4(string& ip) {
        if(count(ip.begin(), ip.end(), '.') != 3) return false;
        vector<string> tokens = split(ip, '.');
        if (tokens.size() != 4) {
            return false;
        }
        for (string token : tokens) {
            if (token.empty() || token.size() > 3 || token.size() > 1 && token[0] == '0') {
                return false;
            }
            for (char c : token) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(token) > 255) {
                return false;
            }
        }
        return true;
    }

    bool validIPv6(string& ip) {
        if(count(ip.begin(), ip.end(), ':') != 7) return false;
        vector<string> tokens = split(ip, ':');
        if (tokens.size() != 8) {
            return false;
        }
        for (string token : tokens) {
            if (token.empty() || token.size() > 4) {
                return false;
            }
            for (char c : token) {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
};

