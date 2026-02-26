class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int tmax = 0;
        int a[]={-1 , 0,1,0};
        int b[]={0,1,0,-1};
        while(!q.empty()){
            int t = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            tmax = max(t,tmax);
            q.pop();
            for(int i = 0;i<4;i++){
                int nrow = r+a[i];
                int ncol = c+b[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow , ncol} , t+1});
                    vis[nrow][ncol]=1;
                    cnt--;
                }
            }

        }
        if(cnt>0)return -1;
        return tmax;
    }
};