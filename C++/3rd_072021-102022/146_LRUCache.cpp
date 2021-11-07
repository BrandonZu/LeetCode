//
// Created by BrandonZu on 9/23/21.
//

#include "common.h"

// Runtime 392ms(>87%) | Memory Cost 165MB(>73%)
class LRUCache {
    class ListNode {
    public:
        int key, val;
        ListNode* pre, * next;
        ListNode(int k = 0, int v = 0) {
            key = k;
            val = v;
            pre = next = nullptr;
        }
    };
    unordered_map<int, ListNode*> hash;
    ListNode* head, * tail;
    int cap;
    int size;
public:
    LRUCache(int capacity) {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->pre = head;
        cap = capacity;
        size = 0;
    }

    inline void insertHead(ListNode* cur) {
        head->next->pre = cur;
        cur->next = head->next;
        cur->pre = head;
        head->next = cur;
    }

    int get(int key) {
        if(hash.find(key) == hash.end()) {
            return -1;
        }
        else {
            ListNode* cur = hash[key];
            // Delete
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            // Insert in the front
            insertHead(cur);

            return cur->val;
        }
    }

    void put(int key, int value) {
        if(hash.find(key) != hash.end()) {
            hash[key]->val = value;
            ListNode* cur = hash[key];
            // Delete
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            // Insert in the front
            insertHead(cur);
        }
        else {
            size++;
            ListNode* cur = new ListNode(key, value);
            hash[key] = cur;
            // Insert in the front
            insertHead(cur);
            if(size > cap) {
                size--;
                ListNode* pre = tail->pre;
                tail->pre->pre->next = tail;
                tail->pre = tail->pre->pre;
                hash.erase(pre->key);
                delete pre;
            }
        }
    }
};
