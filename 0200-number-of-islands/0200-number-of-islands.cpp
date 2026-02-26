class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0; i<n ; i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
    void bfs(int i , int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};
            for(int ri = 0 ;ri<4 ; ri++){
                    int rowi = row+dr[ri];
                    int coli = col+dc[ri];
                    if(rowi>=0 && rowi<n && coli>=0 && coli<m && !vis[rowi][coli] && grid[rowi][coli]=='1'){
                        vis[rowi][coli] = 1;
                        q.push({rowi , coli});
                    }
            }
        }
    }
};