#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution1 {
public:
    string decodeString(string s) {
        int n = s.size();
        string res = "";
        stack<string> strs;
        strs.push("");
        stack<int> nums;
        int num = 0;
        string str = "";
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] == '[') {
                nums.push(num);
                num = 0;
                strs.push(str);
                str = "";
            }
            else if(s[i] == ']') {
                int times = nums.top();
                nums.pop();
                string tmp;
                for(int i = 0; i < times; i++) {
                    tmp += str;
                }
                strs.top() += tmp;
                str = strs.top();
                strs.pop();
            }
            else {
                str += s[i];
            }
        }
        return str;
    }
};

class Solution2 {
public:
    string decodeString(string s) {
        int pos = 0;
        return recur(s, pos);
    }
    string recur(string s, int& pos) {
        int num = 0;
        string res = "";
        while(pos < s.size()) {
            if(s[pos] >= '0' && s[pos] <= '9') {
                num = num * 10 + s[pos] - '0';
                pos++;
            }
            else if(s[pos] == '[') {
                string tmp = recur(s, ++pos);
                for(int j = 0; j < num; j++) {
                    res += tmp;
                }
                num = 0;
                pos++;
            }
            else if(s[pos] == ']') {
                break;;
            }
            else {
                res += s[pos];
                pos++;
            }
        }
        return res;
    }
};