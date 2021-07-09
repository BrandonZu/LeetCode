#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> split;
        s = s + ' ';
        size_t pos = s.find(' ');
        while(pos != string::npos) {
            split.push_back(s.substr(0, pos));
            s = s.substr(pos+1);
            pos = s.find(' ');
        }
        string result;
        for(auto& str : split) {
            reverse(str.begin(), str.end());
            result += str + ' ';
        }
        result.pop_back();
        return result;
    }
};
