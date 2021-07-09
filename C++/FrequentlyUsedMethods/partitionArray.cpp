#include <vector>
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
