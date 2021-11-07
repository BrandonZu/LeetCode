#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
using namespace std;

// Split
vector<string> stringSplit(const string& str, const string& deli) {
    vector<string> tokens;

    string::size_type start = 0, end = 0;
    while((end = str.find(deli, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + deli.size();
    }
    tokens.push_back(str.substr(start));
    return tokens;
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

// Left Trim
string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), [] (char c) {return !isspace(c);})
            );

    return s;
}


// Right Trim
string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), [] (char c) {return !isspace(c);}).base(),
            s.end()
            );

    return s;
}

int main() {
    string str = "1,,2,,3,,4,,5";
    string deli = ",,";
    vector<string> res = stringSplit(str, deli);
    cout << "size: " << res.size() << endl;
    for(string ss: res) {
        if(ss.empty())
            cout << "empty!!" << endl;
        else
            cout << ss << endl;
    }
    return 0;
}

