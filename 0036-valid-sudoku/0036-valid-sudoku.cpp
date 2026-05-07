class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<9;i++){
            vector<int>h(10,0);
            for(int j = 0;j<9 ;j++){
               if(board[i][j]!='.'){ 
               h[board[i][j]-'0']++;
                if(h[board[i][j]-'0']>1)return false;
                }
            }
        }
        for(int i = 0;i<9;i++){
            vector<int>h(10,0);
            for(int j = 0;j<9 ;j++){
                if(board[j][i]!='.'){
                  h[board[j][i]-'0']++;
                if(h[board[j][i]-'0']>1)return false;  
                }
                
            }
        }
        for(int i =1 ; i<=3 ; i++){
            for(int j = 1; j<=3 ;j++){
                vector<int>h(10,0);
                for(int a = (i-1)*3 ; a<(i*3) ; a++){
                    for(int b = (j-1)*3 ; b<(j*3) ; b++){
                        if(board[a][b]!='.'){
                           h[board[a][b]-'0']++;
                        if(h[board[a][b]-'0']>1)return false; 
                        }
                        
                    }
                }
            }
        }
        return true;
    }
};