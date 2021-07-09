#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;

        int pos = 0;
        // Skip spaces
        while(pos <= s.size() - 1 && s[pos] == ' ')
            pos++;

        // Decide the sign
        if(pos <= s.size() - 1 && s[pos] == '-') {
            sign = -1;
            pos++;
        }
        else if (pos <= s.size() - 1 && s[pos] == '+') {
            pos++;
        }

        // Convert string to integer
        while(pos <= s.size() - 1 && s[pos] >= '0' && s[pos] <= '9') {
            result = result * 10 + s[pos] - '0';
            if(sign * result >= INT_MAX)
                return INT_MAX;
            if(sign * result <= INT_MIN)
                return INT_MIN;
            pos++;
        }

        return sign * result;

    }
};

