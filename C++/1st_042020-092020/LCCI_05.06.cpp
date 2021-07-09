#include <iostream>
#include <string>
#include <queue>
using namespace std;
const char d = ' ';

vector<string> mySplit(const string& src) {
    vector<string> res;
    size_t pre = 0;
    size_t pos = res.find(d);
    while(pos != string::npos) {
        string tmp = src.substr(pre, pos - pre);
        res.push_back(tmp);
        pre = pos + 1;
        pos = res.find(d, pos + 1);
    }
    string last = src.substr(pre);
    res.push_back(last);
    return res;
}

bool check(vector<vector<int>>& table, int x, int y, int n, int m) {
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(table[x][y] != -1)
        return false;
    return true;
}

void paint(vector<vector<int>>& table) {
    int n = table.size();
    if(n == 0) return;
    int m = table[0].size();
    int x = 0, y = 0;
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(0, 0));
    table[0][0] = 0;
    int cur_num = 1;
    while(!bfs.empty()) {
        int len = bfs.size();
        for(int i = 0; i < size; i++) {
            auto pos = bfs.pop();
            if(check(table, pos.first + 1, pos.second, n, m)) {
                bfs.push(make_pair(pos.first + 1, pos.second));
                table[pos.first + 1][pos.second] = cur_num;
            }
            if(check(table, pos.first, pos.second + 1, n, m)) {
                bfs.push(make_pair(pop.first, pop.second + 1));
                table[pos.first][pos.second + 1] = cur_num;
            }
        }
        cur_num++;
    }
}

dp[i] =

