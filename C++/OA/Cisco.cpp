//
// Created by BrandonZu on 10/27/21.
//


#include "common.h"

using namespace std;

int validInterpretations (string decInput)
{
    int n = decInput.size();
	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; i++) {
	    char pre = decInput[i - 2];
	    char cur = decInput[i - 1];
	    if(pre == '1' || (pre == '2' && (cur >= '0' && cur <= '5'))) {
	        dp[i] = dp[i - 1] + dp[i - 2];
	    }
	    else {
	        dp[i] = dp[i - 1];
	    }
	}
    return dp[n - 1];
}

/*
 *
 */

int x_dir[4] = {0, 0, 1, -1};
int y_dir[4] = {1, -1, 0, 0};

bool dfs(vector<vector<char> >& board, string& word, int x, int y, int s_pos) {
    if(board[x][y] != word[s_pos])
        return false;
    if(s_pos == word.size() - 1)
        return true;

    int tmp = board[x][y];
    board[x][y] = '*';
    for(int i = 0; i < 4; i++) {
        x += x_dir[i], y += y_dir[i];
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
            if(dfs(board, word, x, y, s_pos + 1))
                return true;
        }
        x-= x_dir[i], y -= y_dir[i];
    }
    board[x][y] = tmp;
    return false;
}

string exist(vector<vector<char> >& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(dfs(board, word, i, j, 0))
                return "Yes";
        }
    }
    return "No";
}

vector<string> isWordPresent (vector<vector<char> > letters, vector<string> words)
{
    vector<string>  answer;
    for(string& word: words)
        answer.push_back(exist(letters, word));
    return answer;
}

int main()
{
    //input for letters
    int letters_row;
    int letters_col;
    cin >> letters_row;
    cin >> letters_col;

    vector<vector<char> > letters;
    for ( int idx = 0; idx < letters_row; idx++ )
    {
        vector<char> temp_vector;
        for ( int jdx = 0; jdx < letters_col; jdx++ )
        {
            char temp;
            cin >> temp;
            temp_vector.push_back(temp);
        }
        letters.push_back(temp_vector);
    }


    //input for words
    int words_size;
    cin >> words_size;
    vector<string> words;
    for ( int idx = 0; idx < words_size; idx++ )
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    //output
    vector<string> result = isWordPresent(letters, words);
    for ( int idx = 0; idx < result.size() - 1; idx++ )
    {
        cout << result[idx] << " ";
    }
    cout << result[result.size() - 1];

    return 0;
}