//
// Created by BrandonZu on 1/9/22.
//

#include "common.h"
#include "ListNode.h"

// Runtime 89ms(>15%) | Memory Usage 14.7MB(>30%)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tmp = headA;
        while(tmp) {
            ++lenA;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp) {
            ++lenB;
            tmp = tmp->next;
        }
        ListNode* tmpA = headA, * tmpB = headB;
        if(lenA >= lenB) {
            for(int i = 0; i < lenA - lenB; i++)
                tmpA = tmpA->next;
        }
        else {
            for(int i = 0; i < lenB - lenA; i++)
                tmpB = tmpB->next;
        }
        while(tmpA && tmpB) {
            if(tmpA == tmpB)
                return tmpA;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return nullptr;
    }
};

// Runtime 66ms(>26%) | Memory Usage 14.3MB(>99%)
class Solution_2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA, * ptrB = headB;

        while(ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

// R .92 | M .33
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA, * pB = headB;
        bool pAReset = false, pBReset = false;
        while(pA != pB) {
            if(pA->next) {
                pA = pA->next;
            }
            else {
                if(!pAReset) {
                    pA = headB;
                    pAReset = true;
                }
                else {
                    break;
                }
            }

            if(pB->next) {
                pB = pB->next;
            }
            else {
                if(!pBReset) {
                    pB = headA;
                    pBReset = true;
                }
                else {
                    break;
                }
            }
        }
        return pA == pB ? pA : nullptr;
    }
};