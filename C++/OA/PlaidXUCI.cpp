//
// Created by BrandonZu on 10/25/21.
//

#include "common.h"
// Problem 1
int main1() {
    int n, m;
    cin >> n >> m;
    vector<int> classes(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> classes[i];
        sum += classes[i];
    }

    int cnt = 0;
    cnt += m / sum * n;
    m = m % sum;
    int pos = 0;
    while(m > 0) {
        if(m >= classes[pos]) {
            m -= classes[pos];
            cnt++;
            pos++;
        }
        else {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}

// Problem 2
int main2() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(m);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int cnt = 0;
    int len = 0;
    int pos = 0;
    while(pos < m) {
        int origin = nums[pos];
        while(pos + 1 < m && nums[pos + 1] <= nums[pos] + 1) {
            pos++;
        }
        len += nums[pos] - origin + 1;
        cnt++;
        pos++;
    }
    cout << len << ' ' << cnt << endl;
    return 0;
}

// Problem 3
int main3() {
    string s, p;
    cin >> s >> p;
    int n = s.size();
    int p_freq[26] = {};
    for(char c: p) {
        if(islower(c)) {
            p_freq[c - 'a']++;
        }
        else {
            p_freq[c - 'A']--;
        }
    }

    int cnt = 0;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(26, 0)));
    for(int i = 1; i <= n; i++) {
        if(islower(s[i - 1]))
            dp[i][i][s[i - 1] - 'a']++;
        else
            dp[i][i][s[i - 1] - 'A']--;
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for(int k = 0; k < 26; k++)
                dp[i][j][k] = dp[i][j - 1][k];
            if(islower(s[j - 1]))
                dp[i][j][s[j - 1] - 'a']++;
            else
                dp[i][j][s[j - 1] - 'A']--;
            bool flag = true;
            for(int k = 0; k < 26; k++) {
                if(dp[i][j][k] != p_freq[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

// Problem 4
int visited[10];
double dis[10][10];
vector<pair<int, int>> points(10);
int res = 0;
int max_left;

void dfs(int pos, int n, int left_len) {
    if(n == 1 && left_len <= max_left) {
        res++;
        return;
    }
    visited[pos] = true;
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        if(dis[pos][i] <= left_len) {
            dfs(i, n - 1, left_len - dis[pos][i]);
        }
    }
    visited[pos] = false;
}

int main() {
    int n, l_min, l_max;
    cin >> n >> l_min >> l_max;
    max_left = l_max - l_min;
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dis[i][j] = sqrt(pow(points[i].first - points[i].second, 2) + pow(points[j].first - points[j].second, 2));
        }
    }
    for(int i = 0; i < n; i++) {
        dfs(i, n, l_max);
    }
    cout << res / 2 << endl;
    return 0;
}

// Problem 5
const int MOD = 1e9 + 7;

bool inf = false;
int target;
int cnt = 0;

void dfs(vector<vector<int>>& jump, int pos, unordered_set<int>& visited) {
    while(!inf && pos != target) {
        cnt = (cnt + 1) % MOD;
        if(visited.find(pos) != visited.end()) {
            inf = true;
            break;
        }
        visited.insert(pos);
        if(jump[pos].size() == 1) {
            pos = jump[pos][0];
        }
        else {
            unordered_set<int> origin = visited;
            for(int i = 0; i < (int)jump[pos].size(); i++) {
                dfs(jump, jump[pos][i], visited);
                visited = origin;
            }
            break;
        }
    }
    if(pos == target) cnt = (cnt + 1) % MOD;
}

int main5() {
    vector<vector<int>> jump(1, vector<int>());
    string tmp;
    while(getline(std::cin, tmp)) {
        int pos = 0;
        jump.emplace_back();
        while(pos < (int)tmp.size()) {
            if(!isdigit(tmp[pos])) {
                pos++;
                continue;
            }
            int num = 0;
            while(pos < (int)tmp.size() && isdigit(tmp[pos])) {
                num *= 10, num += tmp[pos] - '0';
                pos++;
            }
            jump.back().push_back(num);
        }
    }
    target = jump.size() - 1;
    unordered_set<int> visited;

    dfs(jump, 1, visited);

    if(inf) {
        cout << "INFINITE" << endl;
    }
    else {
        cout << cnt % MOD << endl;
    }
    return 0;
}
