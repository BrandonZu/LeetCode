//
// Created by BrandonZu on 9/25/21.
//

#include "common.h"

// Runtime 272ms(>93%) | Memory Usage 117MB(>67%)
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if(maxHeap.empty()) {
            maxHeap.push(num);
        }
        else if(num <= maxHeap.top()) {
            maxHeap.push(num);
            if(maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else {
            minHeap.push(num);
            if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else {
            return maxHeap.top();
        }
    }
};

// Runtime 328ms(>47%) | Mmeory Usage 128MB(>7%)
class MedianFinder_MultiSet {
    int size;
    multiset<int> numSet;
    multiset<int>::iterator med;
public:
    MedianFinder_MultiSet() {
        size = 0;
    }

    void addNum(int num) {
        size++;
        numSet.insert(num);
        if(size == 1) {
            med = numSet.find(num);
        }
        else {
            if(num > *med) {
                if(size % 2 == 1) {
                    med = next(med);
                }
            }
            else if(num < *med) {
                if(size % 2 == 0) {
                    med = prev(med);
                }
            }
            else {
                if(size % 2 == 1) {
                    med = next(med);
                }
            }
        }
    }

    double findMedian() {
        if(size % 2 == 0) {
            return (*med + *next(med)) / 2.0;
        }
        else {
            return *med;
        }
    }
};

// R .92 | M .14
class MedianFinder2 {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
public:
    MedianFinder2() {

    }

    void addNum(int num) {
        if(!minHeap.empty() && num > maxHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
    }

    double findMedian() {
        int totalSize = minHeap.size() + maxHeap.size();
        while(minHeap.size() < totalSize / 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while(minHeap.size() > totalSize / 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(totalSize % 2 == 0) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else {
            return maxHeap.top();
        }
    }
};