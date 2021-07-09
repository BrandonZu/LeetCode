#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> stringSplit(const string& str, const string& deli) {
    vector<string> result;
    if(str.empty()) {
        return result;
    }
    string tmp = str + deli;
    size_t pos = tmp.find(deli);
    size_t pre = 0;
    while(pos != string::npos) {
        result.push_back(tmp.substr(pre, pos - pre));
        pre = pos + 1;
        pos = tmp.find(deli, pos + 1);
    }

    return result;
}

vector<string> stringSplit(const string& str, const char& deli) {
    stringstream ss(str);
    string cur;
    vector<string> result;
    while(getline(ss, cur, deli)) {
        result.push_back(cur);
    }
    return result;
}

int main() {
    string str = "1,2,3,4,,5";
    string deli = ",";
    vector<string> res = stringSplit(str, deli, ',');
    cout << res.size() << endl;
    for(string ss: res) {
        if(ss.empty())
            cout << "empty!!" << endl;
        else
            cout << ss << endl;
    }
    return 0;
}

