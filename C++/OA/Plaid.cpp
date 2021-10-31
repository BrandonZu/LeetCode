//
// Created by BrandonZu on 10/30/21.
//

#include "common.h"

void insert(string& str, stack<int>& add_remove, vector<vector<string>>& input, int i) {
    str.append(input[i][2]);
    add_remove.push(i);
}

void del(string& str, stack<int>& add_remove, vector<vector<string>>& input, int i) {
    string back_str;
    if(!str.empty()) {
        back_str = str.back();
        str.pop_back();
    }
    add_remove.push(i);
    // Keep Record for ruther reference
    input[i].push_back(back_str);
}

string plaidTextEditor(vector<vector<string>> input) {
    sort(input.begin(), input.end(), [&] (vector<string>& a, vector<string>& b) { return stol(a[0]) < stol(b[0]); });
    string str;
    stack<int> add_remove;
    stack<pair<int, int>> undo;
    pair<int, int> select = {-1, -1};
    for(int i = 0; i < input.size(); i++) {
        string& oper = input[i][1];
        if(oper == "INSERT") {
            insert(str, add_remove, input, i);
        }
        else if(oper == "DELETE") {
            del(str, add_remove, input, i);
        }
        else if(oper == "UNDO") {
            if(add_remove.empty()) {
                undo.push({i, -1});
            }
            else {
                int index = add_remove.top();
                string& tmp = input[index][1];
                if(tmp == "INSERT") {
                    for(int i = 0; i < input[index][2].size(); i++)
                        str.pop_back();
                    add_remove.pop();
                }
                else {
                    str.append(input[index][2]);
                    add_remove.pop();
                }
                undo.push({i, index});
                add_remove.pop();
            }
        }
        else if(oper == "REDO") {
            if(!undo.empty() && undo.top().first == i - 1) {
                string& tmp = input[undo.top().second][1];
                if(tmp == "INSERT") {
                    insert(str, add_remove, input, undo.top().second);
                }
                else {
                    del(str, add_remove, input, undo.top().second);
                }
            }
        }
        else if(oper == "SELECT") {
            int start = stol(input[i][2]), end = stol(input[i][3]);
        }
        else if(oper == "BOLD") {
            if(i > 0 && input[i - 1][1] == "SELECT") {
                int start = stol(input[i][2]);
                if(start < 0 || start >= str.size()) continue;
                int end = stol(input[i][3]);
                str.insert(start, "*");
                if(end >= str.size())
                    str.push_back('*');
                else
                    str.insert(end + 1, "*");
            }
        }
    }
    return str;
}

