#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        auto str1 = num1.rbegin(), str2 = num2.rbegin();
        int carry = 0;
        while(str1 != num1.rend() && str2 != num2.rend()) {
            int cur = (*str1 - '0') + (*str2 - '0') + carry;
            carry = cur > 9 ? 1 : 0;
            result.push_back('0' + cur % 10);
            str1++;
            str2++;
        }
        while(str1 != num1.rend()) {
            int cur = *str1 - '0' + carry;
            carry = cur > 9 ? 1 : 0;
            result.push_back('0' + cur % 10);
            str1++;
        }
        while(str2 != num2.rend()) {
            int cur = *str2 - '0' + carry;
            carry = cur > 9 ? 1 : 0;
            result.push_back('0' + cur % 10);
            str2++;
        }
        if(carry != 0)
            result.push_back('0' + carry);
        reverse(result.begin(), result.end());
        return result;
    }
};

