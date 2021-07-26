//
// Created by BrandonZu on 2021/7/25.
//

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int head, tail;
int space;
int e[N], l[N], r[N];

void insertNodeAtLeft(int val) {
    e[space] = val;

    l[r[head]] = space;
    r[space] = r[head];
    l[space] = head;
    r[head] = space;

    space++;
}

void insertNodeAtRight(int val) {
    e[space] = val;

    l[space] = l[tail];
    r[space] = tail;
    r[l[space]] = space;
    l[tail] = space;

    space++;
}

void deleteKthNode(int pos) {
    r[l[pos]] = r[pos];
    l[r[pos]] = l[pos];
}

void insertKthNodeLeft(int pos, int val) {
    e[space] = val;

    r[space] = pos;
    l[space] = l[pos];

    r[l[pos]] = space;
    l[pos] = space;

    space++;
}

void insertKthNodeRight(int pos, int val) {
    e[space] = val;

    r[space] = r[pos];
    l[space] = pos;

    l[r[pos]] = space;
    r[pos] = space;

    space++;
}

int main() {
    ios_base::sync_with_stdio(false);
    // Dummy Head and Tail
    head = 0;
    tail = 1;
    l[head] = -1, r[head] = 1;
    l[tail] = 0, r[tail] = -1;
    // Next Available Node
    space = 2;

    int n = 0;
    cin >> n;
    string oper;
    int num1, num2;
    for(int i = 0; i < n; i++) {
        cin >> oper;
        if(oper == "L") {
            cin >> num1;
            insertNodeAtLeft(num1);
        }
        else if(oper == "R") {
            cin >> num1;
            insertNodeAtRight(num1);
        }
        else if(oper == "D") {
            cin >> num1;
            deleteKthNode(num1 + 1);
        }
        else if(oper == "IL") {
            cin >> num1 >> num2;
            insertKthNodeLeft(num1 + 1, num2);
        }
        else if(oper == "IR") {
            cin >> num1 >> num2;
            insertKthNodeRight(num1 + 1, num2);
        }
        else
            throw exception();
    }

    int cur = r[head];
    while(cur != tail) {
        cout << e[cur] << ' ';
        cur = r[cur];
    }
    return 0;
}
