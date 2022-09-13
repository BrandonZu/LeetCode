//
// Created by BrandonZu on 9/12/22.
//

#include "common.h"

// R .100 | M .20
class Solution {
public:
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int DaysInMonth(int y, int m) {
        if(m == 2)
            return isLeap(y) ? 29 : 28;
        else
            return days[m - 1];
    }

    vector<int> dateStrToInt(const string& date) {
        vector<int> res(3);
        res[0] = stoi(date.substr(0, 4));
        res[1] = stoi(date.substr(5, 2));
        res[2] = stoi(date.substr(8, 2));
        return res;
    }

    bool isLeap(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }

    int countDays(int y, int m, int d) {
        int res = 0;
        for(int i = 1; i < m; i++) {
            res += DaysInMonth(y, i);
        }
        res += d;
        return res;
    }

    int daysBetweenDates(string date1, string date2) {
        vector<int> d1 = dateStrToInt(date1), d2 = dateStrToInt(date2);
        if(d1 > d2) {
            return daysBetweenDates(date2, date1);
        }
        int res = 0;
        for(int y = d1[0]; y < d2[0]; y++) {
            res += isLeap(y) ? 366 : 365;
        }
        res -= countDays(d1[0], d1[1], d1[2]);
        res += countDays(d2[0], d2[1], d2[2]);
        return res;
    }
};
