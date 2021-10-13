//
// Created by BrandonZu on 10/12/21.
//

#include "common.h"

// Office Design
int getMaxColors(vector<int> prices, int money) {
    if(prices.empty() || money == 0) return 0;
    int l = 0, r = 0;
    int maxLen = 0;
    while(r < prices.size()) {
        money -= prices[r];
        r++;
        while(money < 0 && l < r) {
            money += prices[l];
            l++;
        }
        maxLen = max(maxLen, r - l);
    }
    return maxLen;
}

// Single Image Size Validation
#define lld long long int
const lld KB = 1000, MB = 1e6, GB = 1e9;
lld getMaxSize(string str) {
    if(str == "none")
        return 10 * MB;
    string unit;
    unit.push_back(tolower(str[str.size() - 2]));
    unit.push_back(tolower(str[str.size() - 1]));
    str.pop_back(), str.pop_back();
    lld num = stoll(str);
    if(unit == "kb")
        return num * KB;
    else if(unit == "mb")
        return num * MB;
    else
        return num * GB;
}

vector<vector<string>> validateImageSize(vector<vector<string>> imageUrls, string maxSizeStr) {
    vector<vector<string>> result;
    lld maxSize = getMaxSize(maxSizeStr);
    for(vector<string>& image: imageUrls) {
        vector<string> tmp(2);
        tmp[0] = image[0];
        lld curSize = getMaxSize(image[1]);
        if(curSize > maxSize)
            tmp[1] = "FALSE";
        else
            tmp[0] = "TRUE";
        result.push_back(tmp);
    }
    return result;
}

// What's in a number?
bool isE164(string& address) {
    int pos = 0;
    if(address[0] == '+')
        pos++;
    if(address.size() - pos > 15 || address[pos] == '0')
        return false;
    for(; pos < address.size(); pos++) {
        if(!isdigit(address[pos]))
            return false;
    }
    return true;
}

string validatePhoneNumberFormat(string address) {
    string INVALID = "INVALID_ADDRESS";
    if(address.size() < 1 || address.size() > 258)
        return INVALID;
    // SMS number
    if(address.find(':') == string::npos) {
        if(isE164(address))
            return "SMS";
        else
            return INVALID;
    }
    // Other channel
    int colonPos = address.find(':');
    string provider = address.substr(0, colonPos);
    string identifier = address.substr(colonPos + 1);
    for(char& c: provider) c = (char)toupper(c);
    if(provider == "WECHAT") {
        for(char c: identifier) {
            if(!isalnum(c) && c != '+' && c != '-' && c != '_' && c != '@' || c != '.')
                return INVALID;
        }
        return identifier;
    }
    else if(provider == "WHATSAPP" || provider == "MESSENGER") {
        if(isE164(identifier))
            return "SMS";
        else
            return INVALID;
    }
    return INVALID;
}

string parkingdilemma