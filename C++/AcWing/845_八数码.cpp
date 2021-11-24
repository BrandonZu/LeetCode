//
// Created by BrandonZu on 11/23/21.
//

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
using namespace std;


int main() {
    string start;
    for(int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> dist;
    q.push(start);
    vector<vector<char>> cur_tb(3, vector<char>(3));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < 9; i++) {
            cur_tb[i / 3][i % 3] = cur[i];
        }
    }
    return 0;
}
