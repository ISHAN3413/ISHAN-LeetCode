class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,char>> q;
        for(int i =0;i<m;i++){
           if(board[0][i] == 'O') q.push({{0,i},'O'});
           if(board[n-1][i] == 'O')q.push({{n-1,i},'O'});
        }
        for(int i =0;i<n;i++){
           if(board[i][0] == 'O') q.push({{i,0},'O'});
           if(board[i][m-1] == 'O')q.push({{i,m-1},'O'});
        }
        int nrow[] = {-1 , 0 , 1 ,0};
        int ncol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            char val = q.front().second;
            vis[row][col]=1;
            q.pop();
            ans[row][col]=val;
            for(int i = 0;i<4;i++){
                int rowi = row+nrow[i];
                int coli = col+ncol[i];
                if(rowi>=0 && coli>=0 && rowi<n && coli<m && board[rowi][coli]=='O'&&vis[rowi][coli]==0){
                    q.push({{rowi,coli},board[rowi][coli]});
                }
            }
        }
        board = ans;
    }
};