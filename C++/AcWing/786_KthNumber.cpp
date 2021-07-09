#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int src[N];

inline int partitionArray(int left, int right) {
    int pivot = src[left];
    int low = left;
    for(int high = low + 1; high <= right; high++) {
        if(src[high] <= pivot) {
            low++;
            swap(src[low], src[high]);
        }
    }
    swap(src[low], src[left]);
    return low;
}


int selection(int l, int r, int k) {
    if(l >= r)
        return src[l];

    int pos = partitionArray(l, r);
    if(pos == l + k - 1)
        return src[pos];
    else if(pos > l + k - 1)
        return selection(l, pos - 1, k);
    else
        return selection(pos + 1, r, k - (pos - l + 1));
}

int main() {
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &src[i]);

    int result = selection(0, n - 1, k);

    printf("%d", result);

    return 0;
}
