class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]>0 && vis[i][j]!=1){
                    int area = 0;
                    bfs(i,j,grid,vis,area);
                    ans = max(ans , area);
                }
            }
        }
        return ans;
    }
    void bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis , int &area){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        area+=grid[i][j];
        int rowi[4] = {1,0,-1,0};
        int coli[4] = {0,1,0,-1};
        while(!q.empty()){
            int ri = q.front().first;
            int cj = q.front().second;
            q.pop();
            for(int b = 0;b<4;b++){
                int r = ri+rowi[b];
                int c = cj+coli[b];
                if(r>=0 && c>=0 && r<n && c<m && vis[r][c]!=1 && grid[r][c]!=0){
                    vis[r][c] = 1;
                    q.push({r,c});
                    area+=grid[r][c];
                }
            }
        }
    }
};