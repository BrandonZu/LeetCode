#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string deli = "/";
        vector<string> splits = mySplit(path, deli);
        stack<string> myPath;
        myPath.push("/");
        for(string str : splits) {
            if(str.empty() || str == ".")
                continue;
            else if(str == "..") {
                if(myPath.top() != "/")
                    myPath.pop();
            }
            else {
                myPath.push(str);
            }
        }
        string result;
        while(myPath.size() != 1) {
            result = "/" + myPath.top() + result;
            myPath.pop();
        }
        if(result.empty())
            result = "/";
        return result;
    }

    vector<string> mySplit(const string& str, const string& deli) {
        vector<string> result;
        string tmp = str + deli;
        int pre = 0;
        int pos = tmp.find(deli, pre);
        while(pos != string::npos) {
            result.push_back(tmp.substr(pre, pos - pre));
            pre = pos + 1;
            pos = tmp.find(deli, pre);
        }
        return result;
    }
};

int main() {
    Solution test;
    string path = "/home//fool/";
    cout << test.simplifyPath(path) << endl;
}