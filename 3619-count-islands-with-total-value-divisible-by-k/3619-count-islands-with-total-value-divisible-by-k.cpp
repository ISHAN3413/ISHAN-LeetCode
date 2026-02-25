class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0 ;
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i = 0 ; i<n ;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]>0){
                    long long int cnt = 0;
                    bfs(i , j , grid , vis , cnt);
                    if(cnt%k==0)ans++;
                }
            }
        }
        return ans;
    }
    void bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis , long long int &cnt){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty()){
            int ri = q.front().first;
            int cj = q.front().second;
            cnt+=grid[ri][cj];
            q.pop();
            int c[4] = {1,0,-1,0};
            int r[4] = {0,1,0,-1};
            for(int b=0;b<4;b++){
                int rowi = ri+r[b];
                int coli = cj+c[b];
                if(rowi>=0 && coli>=0 && rowi<n && coli<m && grid[rowi][coli]>0 && vis[rowi][coli]!=1){
                    q.push({rowi,coli});
                    vis[rowi][coli] = 1;
                }
            }
        }
    }
};