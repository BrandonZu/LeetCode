#include <vector>

using namespace std;

class MergeSort {
private:
    vector<int> tmp;
public:
    void mergeSort(vector<int> &data) {
        tmp.reserve(data.size() + 1);
    }

    void mergeSort(vector<int> &data, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);

        // Merge
        int l = left, r = mid + 1, p = left;
        while (l <= mid && r <= right) {
            if (data[l] <= data[r])
                tmp[p++] = data[l++];
            else
                tmp[p++] = data[r++];
        }
        while (l <= mid)
            tmp[p++] = data[l++];
        while (r <= right)
            tmp[p++] = data[r++];

        for (int i = left; i <= right; i++) {
            data[i] = tmp[i];
        }
        return;
    }

    vector<pair<int, int>> tmp;
    vector<int> counter;
    void mergeCount(vector<pair<int, int>>& nums, int l, int r) {
        if(l >= r) return;
        int mid = l + r >> 1;

        mergeCount(nums, l, mid);
        mergeCount(nums, mid + 1, r);

        int i = l, j = mid + 1;
        int pos = l;
        while(i <= mid && j <= r) {
            if(nums[i] > nums[j]) {
                counter[nums[i].second] += r - j + 1;
                tmp[pos++] = nums[i++];
            }
            else {
                tmp[pos++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[pos++] = nums[i++];
        }
        while(j <= r) {
            tmp[pos++] = nums[j++];
        }
        for(int k = l; k <= r; k++) {
            nums[k] = tmp[k];
        }
    }
}


int main() {
    vector<int> src = {3,5,10,2,9,77,0, 777};
    tmp.reserve(src.size() + 1);
    mergeSort(src, 0, src.size() - 1);
    return 0;
}