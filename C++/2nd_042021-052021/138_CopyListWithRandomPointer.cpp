#include <unordered_map>
using namespace std;

class Node {
public:
    Node* next;
    Node* random;
    int val;
    Node(int val = 0) {
        this->random = nullptr;
        this->next = nullptr;
        this->val = val;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        return copyRandomListUsingHashMap(head);
    }

    Node* copyRandomListUsingHashMap(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node* oldList = head, * newList;
        // Copy nodes and put new node and old node together
        while(oldList) {
            newList = new Node(oldList->val);
            nodeMap[oldList] = newList;
            oldList = oldList->next;
        }
        oldList = head;
        while(oldList) {
            Node* newNode = nodeMap[oldList];
            if(oldList->next) {
                newNode->next = nodeMap[oldList->next];
            }
            if(oldList->random) {
                newNode->random = nodeMap[oldList->random];
            }
            oldList = oldList->next;
        }
        return nodeMap[head];
    }

    Node* copyRandomListWithoutHashMap(Node* head) {
        if(!head) return head;
        // Copy each node and link the copy to origin
        Node* p = head;
        while(p) {
            Node* newNode = new Node(p->val);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        p = head;
        // Set the random pointer of the copies
        while(p) {
            if(p->random) {
                Node *copy = p->next;
                copy->random = p->random->next;
            }
            p = p->next->next;
        }
        // Split two lists
        Node* dummy = new Node(-1);
        p = head;
        Node* cur = dummy;
        while(p) {
            Node* p_next = p->next->next;
            cur->next = p->next;
            cur = p->next;
            p->next = p_next;
            p = p_next;
        }
        return dummy->next;
    }
};

