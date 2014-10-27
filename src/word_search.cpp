//  WordSearch
//
//  Given a 2D board and a word, find if the word exists in the grid.
//
//  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
//  are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//  For example,
//  Given board =
//
//  [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
//   ]
//  word = "ABCCED", -> returns true,
//  word = "SEE", -> returns true,
//  word = "ABCB", -> returns false.
//
//  Created by Raysmond on 27/10/14.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 递归，深搜
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size()<=0 || word.size()<=0) return false;
        int row = (int)board.size();
        int col = (int)board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0;i<row;++i)
            for (int j=0; j<col; ++j)
                if(dfs(board, 0, i, j, word, visited))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, int index, int row, int col, const string &word, vector<vector<bool>> &visited){
        if (index == word.size()) return true; //结束条件
        if (row<0 || col<0 || row>=board.size() || col>=board[0].size()) return false; // 越界
        if (visited[row][col]) return false; // 已经访问过，剪枝
        if (word[index]!=board[row][col]) return false; // 不满足条件，剪枝
        
        visited[row][col] = true;
        bool res = dfs(board, index+1, row+1, col, word, visited) ||
                   dfs(board, index+1, row, col+1, word, visited) ||
                   dfs(board, index+1, row-1, col, word, visited) ||
                   dfs(board, index+1, row, col-1, word, visited);
        visited[row][col] = false;
        return res;
    }
};


int main(int argc, const char * argv[])
{
    char s[3][5] = {"ABCE","SFCS","ADEE"};
    vector<vector<char>> board;
    for(int i=0;i<3;i++){
        vector<char> b;
        for(int j=0;j<4;j++)
            b.push_back(s[i][j]);
        board.push_back(b);
    }
    
    Solution solution;
    cout<<"ABCCED: "<<solution.exist(board, "ABCCED")<<endl;
    cout<<"SEE: "<<solution.exist(board, "SEE")<<endl;
    cout<<"ABCB: "<<solution.exist(board, "ABCB")<<endl;
    
    return 0;
}

