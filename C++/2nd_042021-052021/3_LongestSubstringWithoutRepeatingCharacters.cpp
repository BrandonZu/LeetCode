#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> charMap;
        int left = 0, right = 0;
        int size = s.size();
        while(right < size) {
            char cur = s[right];
            charMap[cur]++;
            // Right is the index of the next char
            right++;

            while(charMap[cur] > 1) {
                char out = s[left];
                charMap[out]--;
                left++;
            }
            result = max(result, right - left);
        }
        return result;
    }
};

int main() {
    string s = "abcabcbb";
    Solution test;
    test.lengthOfLongestSubstring(s);
    return 0;
}

