#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int num[N];
int tmp[N];

long result = 0;

void mergeSort(int l, int r) {
    if(l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int i = l, j = mid + 1;
    int pos = l;
    while(i <= mid && j <= r) {
        if(num[i] <= num[j]) {
            tmp[pos++] = num[i++];
        }
        else {
            result += mid - i + 1;
            tmp[pos++] = num[j++];
        }
    }
    while(i <= mid)
        tmp[pos++] = num[i++];

    while(j <= r)
        tmp[pos++] = num[j++];

    for(int zz = l; zz <= r; zz++)
        num[zz] = tmp[zz];
}

int main() {
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    mergeSort(0, n - 1);

    printf("%d\n", result);

    return 0;
}

