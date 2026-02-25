class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0 ; 
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        int nrow[] = {-1 , 0 , 1 , 0};
        int ncol[] = {0 ,1 ,0 ,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                vis[i][0] = 1;
                q.push({i,0});
                }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                vis[i][m-1]=1;
                q.push({i,m-1});
                }
        }
        for(int i=0 ; i<m ; i++){
            if(grid[0][i]==1 && !vis[0][i]){
                vis[0][i]=1;
                q.push({0,i});
                }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                vis[n-1][i]=1;
                q.push({n-1,i});
                }           
        }
        while(!q.empty()){
            int rowi = q.front().first;
            int coli = q.front().second;
            ans++;
            q.pop();
            for(int i = 0;i<4;i++){
                int a = rowi+nrow[i];
                int b = coli+ncol[i];
                if(a>=0 && b>=0 && a<n && b<m && vis[a][b]==0 && grid[a][b] == 1){
                    q.push({a,b});
                    vis[a][b]=1;
                }
            }
        }
        for(int i = 0 ; i<n ;i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j]==1)c++;
            }
        }
        return c-ans;
    }
};