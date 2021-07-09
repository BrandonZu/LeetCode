#include <vector>
#include <iostream>
using namespace std;

int partitionArray_1(vector<int>& src, int left, int right) {
    int pivot = src[left];
    while(left < right) {
        while(src[right] >= pivot && left < right) {
            right--;
        }
        src[left] = src[right];
        while(src[left] <= pivot && left < right) {
            left++;
        }
        src[right] = src[left];
    }
    src[left] = pivot;
    return left;
}


int partitionArray_2(vector<int>& src, int left, int right) {
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

void quickSortArray(vector<int>& src, int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = partitionArray_1(src, left, right);
    // int mid = partitionArray_2(src, left, right);
    quickSort(src, left, mid - 1);
    quickSort(src, mid + 1, right);
}

int main() {
    vector<int> src = {3,5,10,2,9,77,0, 777};
    quickSort(src, 0, src.size() - 1);
    return 0;
}
