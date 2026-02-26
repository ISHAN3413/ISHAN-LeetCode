class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(h(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
        
    }
    bool h(int r,int c,int pr,int pc ,vector<vector<char>>& grid ,vector<vector<int>>& vis){\
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c]=1;
        int a[]={-1 , 0 , 1 ,0};
        int b[]={0 , 1 , 0 , -1};
        for(int i = 0;i<4;i++){
            int nr = r+a[i];
            int nc = c+b[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && (grid[r][c]==grid[nr][nc]) ){
                if(!vis[nr][nc]){
                    if(h(nr,nc,r,c,grid,vis))return true;
                }
                else if(!(nr==pr&&nc==pc)){
                    return true;
                }
            }
        }
        return false;
    }
};