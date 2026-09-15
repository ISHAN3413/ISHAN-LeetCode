class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        int cnt= 0 ;
        for(int i= 0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    bfs(i,j,vis,board);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void bfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int ri[] = {1 , 0 , -1 , 0};
            int d[] = {0 , 1 ,0 ,-1};
            for(int k = 0;k<4 ; k++){
                int nr = r + ri[k];
                int nc = c + d[k];
                if(nr>=0 && nr<n && nc<m && nc>=0 && !vis[nr][nc] && board[nr][nc]=='X'){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
};