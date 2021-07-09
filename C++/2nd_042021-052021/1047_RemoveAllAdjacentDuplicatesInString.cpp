#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        string result;
        for(char c : S) {
            if(stk.empty() || stk.top() != c)
                stk.push(c);
            else
                stk.pop();
        }
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

