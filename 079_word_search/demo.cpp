
#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if (word.size() == 0)
            return true;
        
        char start = word[0];
        
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        
        vector<vector<int>> used(m, vector<int>(n, 0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                
                if (board[i][j] == start) {
                    used[i][j] = 1;
                    bool rel = dfs(board, m, n, i, j, used, word, 1);
                    if (rel)
                        return true;
                    used[i][j] = 0;
                }
            }
        }
        
        return false;
        
    }
    
    bool dfs(vector<vector<char>>& board, int m, int n, int i, int j, vector<vector<int>>& used, string word, int idx) {
        
        if (idx == word.size())
            return true;
        
        if (i-1>=0 && used[i-1][j] == 0 && board[i-1][j] == word[idx]) {
            used[i-1][j] = 1;
            bool rel = dfs(board, m, n, i-1, j, used, word, idx+1);
            if (rel)
                return rel;
            used[i-1][j] = 0;
        }
        
        if (i+1<m && used[i+1][j] == 0 && board[i+1][j] == word[idx]) {
            used[i+1][j] = 1;
            bool rel = dfs(board, m, n, i+1, j, used, word, idx+1);
            if (rel)
                return rel;
            used[i+1][j] = 0;
        }
        
        if (j-1>=0 && used[i][j-1] == 0 && board[i][j-1] == word[idx]) {
            used[i][j-1] = 1;
            bool rel = dfs(board, m, n, i, j-1, used, word, idx+1);
            if (rel)
                return rel;
            used[i][j-1] = 0;
        }
        
        if (j+1<n && used[i][j+1] == 0 && board[i][j+1] == word[idx]) {
            used[i][j+1] = 1;
            bool rel = dfs(board, m, n, i, j+1, used, word, idx+1);
            if (rel)
                return rel;
            used[i][j+1] = 0;
        }
        
        return false;
        
    }



};


int main() {

  Solution demo = Solution();

}
