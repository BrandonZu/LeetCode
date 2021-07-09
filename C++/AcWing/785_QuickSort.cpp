#include <iostream>
using namespace std;

const int N = 1e6 + 1;

int nums[N];
int partition(int l, int r);

void quickSort(int l, int r) {
    if(l >= r)
        return;

    int x = nums[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do
            i++;
        while(nums[i] < x);
        do
            j--;
        while(nums[j] > x);
        if(i < j)
            swap(nums[i], nums[j]);
    }
    quickSort(l, j);
    quickSort(j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    quickSort(0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}


