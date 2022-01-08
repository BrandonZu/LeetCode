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

// 1st Review 12/12/21
// Runtime 408ms(>73%) | Memory Usage 165MB(>81%)
class LRUCache_R1 {
    unordered_map<int, list<pair<int, int>>::iterator> keyToNode;
    list<pair<int, int>> nodeList;
    int cap;
public:
    LRUCache_R1(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        else {
            nodeList.splice(nodeList.begin(), nodeList, keyToNode[key]);
            return keyToNode[key]->second;
        }
    }

    void put(int key, int value) {
        if(get(key) != -1) {
            keyToNode[key]->second = value;
            return;
        }

        if(keyToNode.size() == cap) {
            int key = nodeList.back().first;
            nodeList.pop_back();
            keyToNode.erase(key);
        }

        nodeList.emplace_front(key, value);
        keyToNode[key] = nodeList.begin();
    }
};
