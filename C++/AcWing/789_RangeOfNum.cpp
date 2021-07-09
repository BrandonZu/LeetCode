#include <iostream>
using namespace std;

const int N = 1e5 + 1;

int num[N];

int low_bound(int l, int r, int k) {
    if(l >= r) return l;
    while(l < r) {
        int mid = l + r >> 1;
        // [l, mid] [mid + 1, r]
        if(num[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    if(num[l] != k)
        return -1;
    else
        return l;
}

int high_bound(int l, int r, int k) {
    if(l >= r) return l;
    int low = l, high = r;
    // [l, mid - 1] [mid, r]
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(num[mid] <= k)
            l = mid;
        else
            r = mid - 1;
    }
    if(num[l] != k)
        return -1;
    else
        return l;
}

int main() {
    int n, q, k;
    scanf("%d", &n);
    scanf("%d", &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < q; i++) {
        scanf("%d", &k);
        int low = low_bound(0, n - 1, k);
        int high = high_bound(0, n - 1, k);
        printf("%d %d\n", low, high);
    }

    return 0;
}