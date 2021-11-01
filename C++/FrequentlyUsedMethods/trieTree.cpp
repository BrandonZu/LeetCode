//
// Created by BrandonZu on 10/31/21.
//

#include "common.h"

struct node {
    node* child[10];
    bool flag;
    node() {
        for(int i = 0; i < 10; i++)
            child[i] = nullptr;
        flag = false;
    }
};
node* head = new node();

void insert(vector<int>& nums, int l, int r) {
    node* cur = head;
    for(int i = l; i <= r; i++) {
        if(!cur->child[nums[i]]) {
            cur->child[nums[i]] = new node();
        }
        cur = cur->child[nums[i]];
    }
    cur->flag = true;
}

bool query(vector<int>& nums, int l, int r) {
    node* cur = head;
    for(int i = l; i <= r; i++) {
        if(!cur->child[nums[i]]) return false;
        cur = cur->child[nums[i]];
    }
    return cur->flag;
}

