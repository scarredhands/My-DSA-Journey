//https://leetcode.com/problems/n-queens/submissions/1638685576/

class Solution {
public:
   bool isSafe(vector<string> &board, int n,int i, int j){
    int p=i;
    int q=j;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=p;
    j=q;
    while(j>=0){
         if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }
    i=p;
    j=q;
    while(i<n && j>=0){
         if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
    return true;
   }
    void solve( vector<vector<string>> &ans, int n, int col,  vector<string> &board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;++i){
          
                if(isSafe(board,n,i,col)){
                    board[i][col]='Q';
                    solve(ans,n,col+1,board);
                    board[i][col]='.';
                }

            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;++i){
            board.push_back(s);
        }
        solve(ans,n,0,board);
        return ans;
        
    }
};
