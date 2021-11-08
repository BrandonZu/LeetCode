//
// Created by BrandonZu on 11/8/21.
//

#include "common.h"

// Runtime 0ms(>100%) | Memory Usage 6MB(>58%)
class Solution {
public:
    int maximumSwap(int num) {
        int last_seen[10];
        for(int i = 0; i < 10; i++) last_seen[i] = -1;

        string num_str = to_string(num);

        for(int i = num_str.size() - 1; i >= 0; i--) {
            if(last_seen[num_str[i] - '0'] == -1) {
                last_seen[num_str[i] - '0'] = i;
            }
        }

        for(int i = 0; i < num_str.size(); i++) {
            int cur_num = num_str[i] - '0';
            for(int j = 9; j > cur_num; j--) {
                if(last_seen[j] != -1 && last_seen[j] > i) {
                    swap(num_str[i], num_str[last_seen[j]]);
                    return stoi(num_str);
                }
            }
        }
        return stoi(num_str);
    }
};
