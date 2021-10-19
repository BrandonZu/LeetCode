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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<vector<char>> board(n, vector<char>(n, '0'));
    vector<vector<pair<int, int>>> patterns(10);
    
    char digit;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> digit;
            patterns[digit - '0'].push_back(make_pair(i, j));
            board[i][j] = digit;
        }
    }
    
    int pattern_num;
    char oper;
    const vector<int> dir_i = {0, -1, 0, 1};
    const vector<int> dir_j = {-1, 0, 1, 0};

    vector<vector<char>> origin_board(n, vector<char>(n));
    vector<pair<int, int>> origin_points(3001);
    for(int i = 0; i < k; i++) {
        cin >> pattern_num;
        cin >> oper;
        int dir = -1;
        switch (oper) {
            case 'L': dir = 0; break;
            case 'U': dir = 1; break;
            case 'R': dir = 2; break;
            case 'D': dir = 3; break;
        }
        // Reserve Original Board and Points List
        for(int tt = 0; tt < patterns[pattern_num].size(); tt++) origin_points[tt] = patterns[pattern_num][tt];
        // Try to do the operation
        bool flag = true;
        for(pair<int, int>& point: patterns[pattern_num]) {
            int pos_i = point.first, pos_j = point.second;
            if(pos_i + dir_i[dir] < 0 || pos_i + dir_i[dir] >= n || pos_j + dir_j[dir] < 0 || pos_j + dir_j[dir] >= n || (board[pos_i + dir_i[dir]][pos_j + dir_j[dir]] != '0' && board[pos_i + dir_i[dir]][pos_j + dir_j[dir]] != '0' + pattern_num)) {
                flag = false;
                break;
            }
            point.first += dir_i[dir];
            point.second += dir_j[dir];
        }

        if(!flag) {
            for(int tt = 0; tt < patterns[pattern_num].size(); tt++) patterns[pattern_num][tt] = origin_points[tt];
        }
        else {
            for(int tt = 0; tt < patterns[pattern_num].size(); tt++)
                board[origin_points[tt].first][origin_points[tt].second] = '0';
            for(pair<int, int>& point: patterns[pattern_num])
                board[point.first][point.second] = '0' + pattern_num;
        }
    }
    // Print out the result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}