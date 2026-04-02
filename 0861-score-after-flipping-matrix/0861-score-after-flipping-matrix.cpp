class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i = 0;i<grid.size();i++){
            if(grid[i][0] == 0){
                for(int j = 0;j<grid[i].size();j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        for(int j = 1;j<grid[0].size();j++){
            int na = 0;
            int no = 0;
        for(int i = 0 ; i<grid.size();i++){
            if(grid[i][j]==0)na++;
            else no++;
        }
        if(na>no){
        for(int i = 0 ; i<grid.size();i++){
            grid[i][j] = !grid[i][j];
            }
        }
        }
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                  ans+=(1<<(m-j-1));  
                }
                
            }
        }
        return ans;
    }
};