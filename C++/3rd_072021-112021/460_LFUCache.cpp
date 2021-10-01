//
// Created by BrandonZu on 9/28/21.
//

#include "common.h"

class LFUCache {
public:
    struct Node {
        int key;
        int val;
        Node(int _key, int _val) {
            key = _key, val = _val;
        }
    };
    struct Block {
        int freq;
        list<Node> nodeList;
        Block(int _freq) {
            freq = _freq;
        }
    };
    list<Block> blockList;
    unordered_map<int, list<Node>::iterator> nodeMap;
    unordered_map<int, list<Block>::iterator> blockMap;
    int n;
    LFUCache(int capacity) {
        n = capacity;
    }

    void visitNodeOnce(int key) {
        auto node = nodeMap[key];
        auto block = blockMap[key];
        auto nextBlock = ++block;
        if(nextBlock->freq != block->freq + 1) {
            auto tmp = new Block(block->freq + 1);
            blockList.insert(nextBlock, move(*tmp));
            prev(nextBlock)->nodeList.emplace_back(node->key, node->val);
            nodeMap[key] = prev(nextBlock)->nodeList.end();
            blockMap[key] = ++block;
        }
        else {
            nextBlock->nodeList.emplace_back(node->key, node->val);
            nodeMap[key] = prev(nextBlock)->nodeList.end();
            blockMap[key] = nextBlock;
        }
        // Remove the node from the block
        block->nodeList.erase(node);
        // Delete the empty block
        if(block->nodeList.empty()) {
            blockList.erase(block);
        }
    }

    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end())
            return -1;

        visitNodeOnce(key);

        return nodeMap[key]->val;
    }

    void put(int key, int value) {
        if(n == 0) return;
        if(nodeMap.find(key) == nodeMap.end()) {
            if(nodeMap.size() == n) {
                // Delete least frequently used node
                auto lfuNode = blockList.front().nodeList.front();
                nodeMap.erase(lfuNode.key);
                blockMap.erase(lfuNode.key);
                blockList.front().nodeList.pop_front();
                if(blockList.front().nodeList.empty()) {
                    blockList.pop_front();
                }
            }
            // Add new node to the freq=1 block
            if(blockList.empty() || blockList.front().freq != 1) {
                blockList.emplace_front(1);
            }
            blockList.front().nodeList.emplace_back(key, value);
            nodeMap[key] = prev(blockList.front().nodeList.end());
            blockMap[key] = blockList.begin();
        }
        else {
            nodeMap[key]->val = value;
            visitNodeOnce(key);
        }
    }
};

int main() {
    LFUCache test(2);
    test.put(1, 1);
    test.put(2, 2);
    cout << test.get(1) << endl;
    test.put(3, 3);
    cout << test.get(2) << endl;
    cout << test.get(3) << endl;
    test.put(4, 4);
}
