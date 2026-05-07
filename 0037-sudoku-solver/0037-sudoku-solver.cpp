class Solution {
public:
    bool issafe(vector<vector<char>>& board , int row , int col , char dig){
        for(int i = 0; i < 9 ; i++){
            if(board[row][i]==dig)return false;
            if(board[i][col]==dig)return false;
        }
        int i = (row/3)*3;
        int j = (col/3)*3;
        for(int st = i;st<(i+3);st++){
            for(int en = j;en<(j+3);en++){
                if(board[st][en]==dig)return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board , int row , int col){
        if(row == 9)return true;
        int nextc = col+1;
        int nextr = row;
        if(nextc==9){
            nextc=0;
            nextr=row+1;
        }
        if(board[row][col]!='.'){
            return helper(board,nextr,nextc);
        }
        for(char dig = '1' ; dig<='9';dig++){
            if(issafe(board , row , col , dig)){
                board[row][col] = dig;
                if(helper(board , nextr , nextc)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
       return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};