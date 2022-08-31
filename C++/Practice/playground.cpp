#include "common.h"

int main() {
    unordered_map<int, int> myMap = {{1, 3}, {2, 4}, {3, 6}, {6, 12}, {19, 99}};
    for(auto& [k, v] : myMap) {
        while(true)  {
            cout << k << ":" << v << endl;
        }

    }
    return 0;
}

