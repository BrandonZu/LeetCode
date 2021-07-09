#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(auto p = digits.rbegin(); p != digits.rend(); p++) {
            if(!carry)
                break;
            if(*p == 9) {
                *p = 0;
                carry = true;
            }
            else {
                *p += 1;
                carry = false;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution tmp;
    vector<int> num = {1,2,3};
    tmp.plusOne(num);
}

