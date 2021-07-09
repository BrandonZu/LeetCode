#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
public:
    int key, val;
    Node* pre, * next;
    Node(int key, int val):key(key), val(val), pre(nullptr), next(nullptr) {}
};

class DoublyList {
    Node* head, * tail;
    int size;
public:
    DoublyList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        size = 0;
    }

    int getSize() {
        return size;
    }

    void addFront(Node* node) {
        Node* head_next = head->next;
        head->next = node;
        node->pre = head;
        node->next = head_next;
        head_next->pre = node;
        size++;
    }

    Node* removeBack() {
        Node* node = tail->pre;
        tail->pre = tail->pre->pre;
        tail->pre->next = tail;
        size--;
        return node;
    }

    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        size--;
    }

};

class LRUCache {
    int max_size;
    DoublyList cache;
    unordered_map<int, Node*> nodeMap;
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }

    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        Node* node = nodeMap[key];
        int value = node->val;
        cache.remove(node);
        cache.addFront(node);
        return value;
    }

    void put(int key, int value) {
        // Key already exsits
        if(nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->val = value;
            cache.remove(node);
            cache.addFront(node);
        }
        else {
            if (cache.getSize() == max_size) {
                Node *oldNode = cache.removeBack();
                nodeMap.erase(oldNode->key);
            }
            Node *newNode = new Node(key, value);
            cache.addFront(newNode);
            nodeMap.insert(pair<int, Node*>(key, newNode));
        }
    }
};

int main() {
    LRUCache test(2);
    test.put(1,1);
    test.put(1,2);

}