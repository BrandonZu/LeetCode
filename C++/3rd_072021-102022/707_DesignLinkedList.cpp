//
// Created by BrandonZu on 2021/7/17.
//

#include "common.h"
#include "ListNode.h"

class MyLinkedList {
    int size;
    ListNode* tail;
    ListNode* dummy;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        dummy = new ListNode(-1);
        tail = dummy;
    }

    ListNode* getIndex(int pos) {
        ListNode* cur = dummy;
        for(int i = 0; i <= pos; i++) {
            cur = cur->next;
        }
        return cur;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index > size - 1)
            return -1;
        ListNode* cur = getIndex(index);
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummy->next;
        dummy->next = newNode;

        if(size == 0)
            tail = dummy->next;

        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;

        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        ListNode* cur = getIndex(index - 1);
        ListNode* next = cur->next;
        cur->next = new ListNode(val);
        cur->next->next = next;

        if(index == size)
            tail = cur->next;

        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        ListNode* cur = getIndex(index - 1);
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;

        delete tmp;

        if(index == size - 1)
            tail = cur;

        size--;
    }
};
