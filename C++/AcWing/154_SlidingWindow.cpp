//
// Created by BrandonZu on 2021/7/25.
//

#include <queue>
#include <iostream>
using namespace std;

const int N = 1e6+1;
int winMax[N], winMin[N];

int main() {
    int n, k;
    cin >> n >> k;
    deque<pair<int, int>> qMax, qMin;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(!qMax.empty() && qMax.front().first < i - k + 1)
            qMax.pop_front();
        if(!qMin.empty() && qMin.front().first < i - k + 1)
            qMin.pop_front();

        while(!qMax.empty() && qMax.back().second <= num)
            qMax.pop_back();
        while(!qMin.empty() && qMin.back().second >= num)
            qMin.pop_back();

        qMax.emplace_back(i, num);
        qMin.emplace_back(i, num);

        if(i >= k - 1) {
            winMax[i - k + 1] = qMax.front().second;
            winMin[i - k + 1] = qMin.front().second;
        }
    }

    for(int i = 0; i < n - k + 1; i++)
        cout << winMin[i] << ' ';
    cout << endl;
    for(int i = 0; i < n - k + 1; i++)
        cout << winMax[i] << ' ';


    return 0;
}
