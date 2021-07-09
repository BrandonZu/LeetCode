#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char cur : s) {
            if(cur == '(' || cur == '{' || cur == '[') {
                mystack.push(cur);
            }
            else if(cur == ')') {
                if(mystack.empty() || mystack.top() != '(')
                    return false;
                else
                    mystack.pop();
            }
            else if(cur == '}') {
                if(mystack.empty() || mystack.top() != '{')
                    return false;
                else
                    mystack.pop();
            }
            else if(cur == ']') {
                if(mystack.empty() || mystack.top() != '[')
                    return false;
                else
                    mystack.pop();
            }
        }
        return true;
    }
};

int main() {
    string test = "([{}])";
    Solution solution;
    cout << solution.isValid(test) << endl;
    return 0;
}