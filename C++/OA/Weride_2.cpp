//
// Created by BrandonZu on 10/18/21.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
string cmd;
int min_dist = INT32_MAX;
string cur_path;
char board[50][50];

int get_min_distance(string word1, string word2) {
    vector<int> dp(word2.size() + 1, 0);
    for(int j = 1; j <= word2.size(); j++)
        dp[j] = j;

    int cur, pre;
    for(int i = 1; i <= word1.size(); i++) {
        pre = dp[0];
        dp[0] = i;
        for(int j = 1; j <= word2.size(); j++) {
            cur = dp[j];
            if(word1[i - 1] == word2[j - 1]) {
                dp[j] = pre;
            }
            else {
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            }
            pre = cur;
        }
    }

    return dp[word2.size()];
}

const char dir_char[4] = {'L', 'U', 'R', 'D'};
const int dir_i[4] = {0, -1, 0, 1};
const int dir_j[4] = {-1, 0, 1, 0};

void dfs(int i, int j) {
    if(board[i][j] == 'E') {
        min_dist = min(min_dist, get_min_distance(cmd, cur_path));
        return;
    }
    board[i][j] = 'N';
    for(int dd = 0; dd < 4; dd++) {
        int new_i = i + dir_i[dd], new_j = j + dir_j[dd];
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || board[new_i][new_j] != '.')
            continue;
        cur_path.push_back(dir_char[dd]);
        dfs(new_i, new_j);
        cur_path.pop_back();
    }
    board[i][j] = '.';
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    string tmp;
    int start_i, start_j;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < m; j++) {
            board[i][j] = tmp[j];
            if(tmp[j] == 'R') start_i = i, start_j = j;
        }
    }
    string tmp_cmd;
    cin >> tmp_cmd;
    int tmp_i = start_i, tmp_j = start_j;
    for(char oper: tmp_cmd) {
        int dir;
        switch (oper) {
            case 'L': dir = 0; break;
            case 'U': dir = 1; break;
            case 'R': dir = 2; break;
            case 'D': dir = 3; break;
        }
        int new_i = tmp_i + dir_i[dir], new_j = tmp_j + dir_j[dir];
        if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || board[new_i][new_j] != '.')
            continue;
        else {
            cmd.push_back(oper);
            tmp_i = new_i, tmp_j = new_j;
        }
    }
    dfs(start_i, start_j);
    cout << min_dist << endl;
    return 0;
}

