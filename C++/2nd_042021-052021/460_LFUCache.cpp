#include <unordered_map>
#include <list>
using namespace std;

class Node {
public:
    int key, val, count;
    Node* pre, * next;
    Node(int key, int val):key(key), val(val), count(1), pre(nullptr), next(nullptr) {}
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

    bool isEmpty() {
        return head->next == tail;
    }

};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 1;
    }

    void addCount(Node* node) {
        // Remove node from old frequency list
        freqMap[node->count].remove(node);
        if(freqMap[node->count].isEmpty()) {
            freqMap.erase(node->count);
            if(node->count == minFreq)
                minFreq++;
        }

        // Add node to new frequency list
        node->count++;
        freqMap[node->count].addFront(node);

    }

    int get(int key) {
        if(keyToNodeMap.find(key) == keyToNodeMap.end())
            return -1;
        Node* node = keyToNodeMap[key];

        addCount(node);

        return node->val;
    }

    void put(int key, int value) {
        if(keyToNodeMap.find(key) != keyToNodeMap.end()) {
            keyToNodeMap[key]->val = value;

            addCount(keyToNodeMap[key]);

            return;
        }

        if(keyToNodeMap.size() == capacity) {
            if(capacity == 0)
                return;
            // Remove the least frequently used node
            Node* node = freqMap[minFreq].removeBack();
            keyToNodeMap.erase(node->key);
            if(freqMap[minFreq].isEmpty())
                freqMap.erase(minFreq);
        }

        // Insert new node
        Node* newNode = new Node(key, value);
        keyToNodeMap[key] = newNode;
        freqMap[newNode->count].addFront(newNode);
        minFreq = 1;

    }

private:
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyToNodeMap;
    unordered_map<int, DoublyList> freqMap;
};

int main() {
    LFUCache myCache(2);
    myCache.put(1, 1);
    myCache.put(2, 2);
    myCache.get(1);
    myCache.put(3, 3);
    myCache.get(2);
    myCache.get(3);
    myCache.put(4, 4);
    myCache.get(1);
    myCache.get(3);
    myCache.get(4);
    return 0;
}
