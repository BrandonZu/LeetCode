#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        unordered_map<char, int> current, require;
        int match = 0;
        int min_len = s.size() + 1, str_start = -1;
        for(char tmp : t)
            require[tmp]++;
        while(right < s.size()) {
            // 将当前right加入
            if(require.find(s[right]) != require.end()) {
                current[s[right]]++;
                if (current[s[right]] == require[s[right]])
                    match++;
            }
            right++;
            while(match == require.size()) {
                // 此时right指向后一个字符
                if(right - left < min_len) {
                    min_len = right - left;
                    str_start = left;
                }
                if(require.find(s[left]) != require.end()) {
                    if (current[s[left]] == require[s[left]])
                        match--;
                    current[s[left]]--;
                }
                left++;
            }
        }
        if(str_start == -1)
            return "";
        else
            return s.substr(str_start, min_len);
    }
};

int main() {
    Solution tmp;
    cout << tmp.minWindow("AA", "AA") << endl;
    return 0;
}