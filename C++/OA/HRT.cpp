//
// Created by BrandonZu on 10/16/21.
//

#include "common.h"

// Almost Sorted
int almostSorted(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    int max_len = 0;
    for(int i = 0; i < n; i++) {
        int l = 0, r = max_len;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(dp[mid] < nums[i]) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        max_len = max(max_len, l + 1);
        dp[l + 1] = nums[i];
    }
    return n - max_len - 1;
}

// Simple Text Queries
vector<string> stringSplit(const string& str, const string& deli) {
    vector<string> result;
    if(str.empty()) return result;
    string tmp = str + deli;
    size_t pos = tmp.find(deli);
    size_t pre = 0;
    while(pos != string::npos) {
        result.push_back(tmp.substr(pre, pos - pre));
        pre = pos + deli.size();
        pos = tmp.find(deli, pos + 1);
    }
    return result;
}

vector<vector<int>> textQueries(vector<string> sentences, vector<string> queries) {
    vector<unordered_map<string, int>> sentence_map(sentences.size());
    for(int i = 0; i < sentences.size(); i++) {
        vector<string> words = stringSplit(sentences[i], " ");
        for(string& word: words) {
            sentence_map[i][word]++;
        }
    }
    vector<vector<int>> result;
    for(string& q: queries) {
        vector<string> words = stringSplit(q, " ");
        vector<int> cur;

        for(int i = 0; i < sentences.size(); i++) {
            int minOccur = -1;
            for(string& word: words) {
                if(minOccur == -1)
                    minOccur = sentence_map[i][word];
                else
                    minOccur = min(minOccur, sentence_map[i][word]);
                if(minOccur == 0)
                    break;
            }
            for(int kk = 0; kk < minOccur; kk++)
                cur.push_back(i);
        }

        if(cur.empty())
            cur.push_back(-1);
        result.push_back(cur);
    }
    return result;
}

int main() {
    vector<string> sentences = {"bob and alice like to text each other", "bob does not like to ski but does not like to fall", "Alice likes to ski"};
    vector<string> queries = {"bob alice", "alice", "like", "non occurrence"};
    auto result = textQueries(sentences, queries);
    return 0;
}

// Count Duplicate Elements
int countDuplicate(vector<int> nums) {
    int result = 0;
    unordered_map<int, int> num_set;
    for(int num: nums) {
        if(num_set[num] == 1) {
            result++;
        }
        num_set[num]++;
    }
    return result;
}

// Maximum Binary Sum
string maximumBinarySum(int numberOfBits, int maximumOperationsAllowed, vector<string> arr) {
    sort(arr.begin(), arr.end());
    for(int i = 0; i < maximumOperationsAllowed && i < arr.size(); i++) {
        if(arr[i][0] != '0')
            break;
        // reverse bits
        for(char& c: arr[i]) {
            if(c == '0')
                c = '1';
            else
                c = '0';
        }
    }
    int carry = 0;
    string result = "";
    for(int i = numberOfBits - 1; i >= 0; i--) {
        int tmp = carry;
        for(auto& str: arr) {
            if(str[i] == '1')
                tmp++;
        }
        carry = tmp / 2;
        result.push_back('0' + tmp % 2);
    }
    while(carry != 0) {
        result.push_back('0' + carry % 2);
        carry = carry / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}


// Assign Value to Edge
int assignValue(int N, vector<int>& A, vector<int>& B) {
    vector<int> count(N);
    for(int a: A) count[a - 1]++;
    for(int b: B) count[b - 1]++;
    sort(count.begin(), count.end());
    int result = 0;
    for(int i = count.size() - 1; i >= 0; i--) {
        result += count[i] * N;
        N--;
    }
    return result;
}

// String Transformation
string stringTrans(string& S) {
    string stk;
    for(char c: S) {
        if(!stk.empty()) {
            char top = stk.back();
            if((top == 'A' && c == 'B') || (top == 'B' && c == 'A') || (top == 'C' && c == 'D') || (top == 'D' && c == 'C')) {
                stk.pop_back();
                continue;
            }
        }
        stk.push_back(c);
    }
    return stk;
}

// Retail Stores

int retailStore(int K, vector<vector<int>>& A) {
    unordered_map<int, int> plot;
    int houseCnt = 0;
    int storeCnt = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1) {
                houseCnt++;
            }
        }
    }
    return storeCnt;
}