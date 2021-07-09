#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        int gPos = g.size() - 1;
        for(int pos = s.size() - 1; pos >= 0; pos--) {
            while(gPos >= 0 && g[gPos] > s[pos])
                gPos--;
            if(gPos >= 0) {
                num++;
                gPos--;
            }
        }
        return num;
    }
};

