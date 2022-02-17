//
// Created by BrandonZu on 2/17/22.
//

#include "common.h"

// Runtime 32ms(>49%) | Memory Usage 19.3MB(>100%)
class Vector2D {
public:
    vector<vector<int>>::iterator row, row_end;
    vector<int>::iterator col;

    Vector2D(vector<vector<int>>& vec) {
        row = vec.begin();
        if(!vec.empty())
            col = row->begin();
        row_end = vec.end();
    }

    int next() {
        int ret;
        if(col != row->end()) {
            ret = *col;
            col++;
            return ret;
        }
        else {
            row++;
            col = row->begin();
            ret = *col;
            col++;
            return ret;
        }
    }

    bool hasNext() {
        if(row == row_end)
            return false;
        while(row != row_end && col == row->end()) {
            row++;
            if(row != row_end) {
                col = row->begin();
            }
        }
        return row != row_end && col != row->end();
    }
};
