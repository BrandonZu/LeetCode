//
// Created by BrandonZu on 2021/7/25.
//

#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5 + 10;
int result[N];

int main() {
    ios_base::sync_with_stdio(false);
    stack<int> stk;

    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        while(!stk.empty() && stk.top() >= num)
            stk.pop();

        if(stk.empty())
            result[i] = -1;
        else
            result[i] = stk.top();

        stk.push(num);
    }
    for(int i = 0; i < n; i++)
        cout << result[i] << ' ';
    return 0;
}