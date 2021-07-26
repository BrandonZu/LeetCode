//
// Created by BrandonZu on 2021/7/25.
//

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int head;
int e[N], ne[N];
int space;

void insertNodeAtHead(int val) {
    e[space] = val;
    ne[space] = ne[head];
    ne[head] = space;
    space++;
}

void deleteKthNode(int pos) {
    ne[pos] = ne[ne[pos]];
}

void insertKthNode(int pos, int val) {
    e[space] = val;
    ne[space] = ne[pos];
    ne[pos] = space;
    space++;
}

int main() {
    ios_base::sync_with_stdio(false);
    // Dummy Head
    head = 0;
    e[head] = -1;
    ne[head] = -1;
    // Next Available Node
    space = 1;

    int n = 0;
    cin >> n;
    char oper;
    int num1, num2;
    for(int i = 0; i < n; i++) {
        cin >> oper;
        if(oper == 'H') {
            cin >> num1;
            insertNodeAtHead(num1);
        }
        else if(oper == 'D') {
            cin >> num1;
            deleteKthNode(num1);
        }
        else if(oper == 'I') {
            cin >> num1 >> num2;
            insertKthNode(num1, num2);
        }
        else
            throw exception();
    }

    int cur = ne[head];
    while(cur != -1) {
        cout << e[cur] << ' ';
        cur = ne[cur];
    }
    return 0;
}
