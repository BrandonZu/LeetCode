//
// Created by BrandonZu on 11/23/21.
//

#include "common.h"

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        long hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return (int)hash;
    }
};

