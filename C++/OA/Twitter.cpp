//
// Created by BrandonZu on 10/19/21.
//

#include "common.h"

// Twitter New Office Design
int officeDesign(vector<int> tablePositions, vector<int> tableHeights) {
    int maxHeight = 0;
    for(int i = 1; i < tablePositions.size(); i++) {
        if(tablePositions[i] - tablePositions[i - 1] > 1) {
            int pos_1 = tablePositions[i - 1], pos_2 = tablePositions[i];
            int taller = max(tableHeights[pos_1], tableHeights[pos_2]);
            int shorter = min(tableHeights[pos_1], tableHeights[pos_2]);
            if(taller >= shorter + (pos_2 - pos_1)) {
                maxHeight = max(maxHeight, shorter + (pos_2 - pos_1));
            }
            else {
                maxHeight = max(maxHeight, taller + (pos_2 - pos_1 - (taller - shorter) + 1) / 2);
            }
        }
    }
    return maxHeight;
}

// Efficient Job Processing Service
int maximumTotalWeight(vector<int> tasks, vector<int> weights, int p) {
    vector<int> dp(p + 1, 0);
    for(int i = 1; i <= tasks.size(); i++) {
        for(int j = tasks[i - 1] * 2; j <= p; j++) {
            dp[j] = max(dp[j], dp[j - tasks[i - 1] * 2] + weights[i - 1]);
        }
    }
    return dp[p];
}

// Game Event


// Unique Twitter User Id Set
int getUniqueUserIdSum(vector<int> arr){
    int sum = 0;
    sort(arr.begin(), arr.end());
    int pre = 0;
    for(int i: arr) {
        int cur = max(pre + 1, i);
        sum += cur;
        pre = cur;
    }
    return sum;
}

// Partitioning array
bool PartitioningArray(vector<int> &nums, int k) {
    // write your code here
    int n = nums.size();
    if(n % k != 0)
        return false;
    int maxPresent = n / k;
    unordered_map<int, int> num_map;
    for(int num: nums) {
        num_map[num]++;
        if(num_map[num] > maxPresent)
            return false;
    }
    return true;
}

// Autoscale Policy
int finalInstances(int instances, vector<int> averageUtil) {
    for(int i = 0; i < averageUtil.size(); i++) {
        if(averageUtil[i] < 25) {
            if(instances == 1)
                continue;
            instances = (instances + 1) / 2;
            i += 10;
        }
        else if(averageUtil[i] > 60) {
            if(instances * 2 > 2 * 1e8)
                continue;
            instances *= 2;
            i += 10;
        }
    }
    return instances;
}

// Authentication Tokens
int numberOfTokens(int expireLimit, vector<vector<int>> commands) {
    int cur_time = commands.back()[2];
    unordered_map<int, int> token_map;
    for(auto& p: commands) {
        if(p[0] == 0) {
            // Get
            if(token_map.find(p[1]) == token_map.end()) {
                token_map[p[1]] = p[2] + expireLimit;
            }
        }
        else {
            // Reset
            if(token_map.find(p[1]) == token_map.end())
                continue;
            if(token_map[p[1]] >= p[2])
                token_map[p[1]] = p[2] + expireLimit;
        }
    }
    int cnt = 0;
    for(auto& p: token_map) {
        if(p.second > cur_time)
            cnt++;
    }
    return cnt;
}

// K Difference == Leetcode 532
int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> num_map;
    for(int num: nums)
        num_map[num]++;
    int cnt = 0;
    for(auto p: num_map) {
        if(k == 0 && p.second > 1)
            cnt++;
        else if(k != 0 && num_map.find(p.first + k) != num_map.end())
            cnt++;
    }
    return cnt;
}

// Balanced Array
int BalancedSalesArray(vector<int> &sales) {
    int total_sum = 0;
    for(int sale: sales) total_sum += sale;
    int cur_sum = 0;
    for(int i = 0; i < sales.size(); i++) {
        if(cur_sum * 2 == total_sum - sales[i])
            return i;
        cur_sum += sales[i];
    }
    return -1;
}

// Parking Dilemma
int ParkingDilemma(vector<int> &cars, int k) {
    sort(cars.begin(), cars.end());
    int min_len = INT_MAX;
    for(int i = 0; i + k - 1 < cars.size(); i++) {
        min_len = min(min_len, cars[i + k - 1] - cars[i] + 1);
    }
    return min_len;
}

// Palindromic Substrings
int countPalindromicSubstrings(string& s) {
    vector<bool> dp(s.size() + 1, false);
    int res = 0;
    unordered_set<string> str_set;
    for(int l = s.size(); l >= 1; l--) {
        for(int r = s.size(); r >= l; r--) {
            if(s[l - 1] == s[r - 1]) {
                if(r - l <= 1 || dp[r - 1]) {
                    dp[r] = true;
                    res++;
                }
                else
                    dp[r] = false;
            }
            else {
                dp[r] = false;
            }
        }
    }
    return res;
}

// Weird Faculty
int exam(vector<int> v) {
    int totalSum = 0;
    for(int score: v) {
        if (score == 0) totalSum -= 1;
        else totalSum += 1;
    }

    int currSum = 0;
    for(int i = 0; i < v.size(); i++) {
        if (currSum > totalSum) return i;
        currSum += v[i] == 0 ? -1 : 1;
        totalSum -= v[i] == 0 ? -1 : 1;
    }
    return v.size();
}

// Final Discounted price
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> decrease;
    vector<int> result(temperatures.size(), 0);
    for(int i = 0; i < temperatures.size(); i++) {
        while(!decrease.empty() && temperatures[decrease.top()] < temperatures[i]) {
            result[decrease.top()] = i - decrease.top();
            decrease.pop();
        }
        decrease.push(i);
    }
    return result;
}

// Reaching Points
bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx < tx && sy < ty) {
        if (tx < ty)
            ty %= tx;
        else
            tx %= ty;
    }
    return (sx == tx && sy <= ty && (ty - sy) % sx == 0) || (sy == ty && sx <= tx && (tx - sx) % sy == 0);
}

// Twitter Social Network
class Solution {
    vector<bool> visited;
public:
    void dfs(vector<vector<int>>& isConnected, int node) {
        visited[node] = true;
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && !visited[i]) {
                dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        visited.resize(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, i);
                count++;
            }
        }
        return count;
    }
};

// Active Fountain
int numFountains(vector<int> fountains) {
    int n = fountains.size();
    vector<int> extents(n, 0);

    for (int i = 0; i < n; i++) {
        int left = max(i - fountains[i], 0);
        int right = min(i + (fountains[i] + 1), n);
        extents[left] = max(extents[left], right);
    }

    int num_fountains = 1;
    int right = extents[0], next_right = 0;
    for (int i = 0; i < n; i++) {
        next_right = max(next_right, extents[i]);
        if (i == right) {
            num_fountains++;
            right = next_right;
        }
    }

    return num_fountains;
}

// Coloring the blocks
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
        // Init
        for(int i = 0; i < 3; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++) {
            // Red
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            // Green
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            // Blue
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};

// Get set on
class Solution {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;
public:
    void dfs(const vector<int>& candidates, int pos, int target) {
        if(pos >= candidates.size()) return;
        for(int i = pos; i < candidates.size(); i++) {
            // Remove Duplicates
            if(i - 1 >= 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])
                continue;

            path.push_back(candidates[i]);
            visited[i] = true;

            if(target - candidates[i] > 0)
                dfs(candidates, i + 1, target - candidates[i]);
            else if(target - candidates[i] == 0)
                result.push_back(path);

            visited[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        visited.resize(candidates.size(), false);
        dfs(candidates, 0, target);
        return result;
    }
};

// Game Event
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

struct GameInfo{
    string team = "";
    string player1;
    int time;
    int extra = 0;
    char event;
    string player2 = "";
    int index;
};


void setPlayer (GameInfo & info ,vector <string>& tokens){
    stringstream temp;
    info.event = tokens.back()[0];
    string time;
    if (tokens.size() == 4){
        temp << tokens[2];
        time = tokens[2];
        info.player1 = tokens[0] + " " + tokens[1];
    }
    else{
        temp << tokens[1];
        time = tokens[1];
        info.player1 = tokens[0];
    }

    string intermediate = "";
    getline(temp , intermediate , '+');
    info.time = stoi(time);
    if (intermediate.length() != time.length()){
        getline(temp , intermediate , '+');
        info.extra = stoi(intermediate);
    }
}

GameInfo getTokens (string s){
    stringstream temp (s);
    vector <string> tokens;
    string intermediate = "";
    while (getline (temp , intermediate , ' ')){
        tokens.push_back(intermediate);
    }

    GameInfo currGame;
    if (tokens.back().length() > 1){ //name
        currGame.player2 += tokens.back();
        tokens.pop_back();
        if (tokens.back().length() > 1){ //firstname
            currGame.player2 = tokens.back() + " " + currGame.player2;
            tokens.pop_back();
        }
    }

    setPlayer(currGame, tokens);
    return currGame;
}

bool compare (const GameInfo & info1 , const GameInfo & info2){
    unordered_map <char, int> helper;
    helper['G'] = 0;
    helper['Y'] = 1;
    helper['R'] = 2;
    helper['S'] = 3;
    if (info1.time == info2.time){
        if (info1.extra == info2.extra){
            if (helper[info1.event] == helper[info2.event]){
                if (info1.team == info2.team){
                    if (info1.player1 == info2.player1){
                        return info1.player2 <= info2.player2;
                    }
                    return info1.player1 < info2.player1;
                }
                return info1.team < info2.team;
            }
            return helper[info1.event] < helper[info2.event];
        }
        return info1.extra < info2.extra;
    }
    return info1.time < info2.time;
}

vector <string> findRes (string team1 , string team2 , vector<string> & event1 , vector<string> & event2){
    vector <GameInfo> events;
    GameInfo info;
    for (int i=0 ; i<event1.size() ; i++){
        info = getTokens(event1[i]);
        info.team = team1;
        info.index = i;
        events.push_back(info);
    }

    for (int i=0 ; i<event2.size() ; i++){
        info = getTokens(event2[i]);
        info.team = team2;
        info.index = i;
        events.push_back(info);
    }
    sort (events.begin() , events.end() , compare);
    vector <string> res;
    for (int i=0 ; i<events.size() ; i++){
        if (events[i].team == team1){
            res.push_back(team1 + " " + event1[events[i].index]);
        }
        else{
            res.push_back(team2 + " " + event2[events[i].index]);
        }
    }
    return res;
}
