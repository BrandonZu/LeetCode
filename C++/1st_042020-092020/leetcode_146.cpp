#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>:: iterator> link;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if(link.find(key) == link.end())
            return -1;
        pair<int, int> target = *link[key];
        cache.erase(link[key]);
        // Put it to the front
        cache.push_front(target);
        link[key] = cache.begin();
        return target.second;
    }

    void put(int key, int value) {
        if(link.find(key) == link.end()) {
            if(cache.size() == cap) {
                auto key_pair = cache.back();
                int key = key_pair.first;
                link.erase(key);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            link[key] = cache.begin();

        }
        else {
            cache.erase(link[key]);
            cache.push_front(make_pair(key, value));
            link[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
