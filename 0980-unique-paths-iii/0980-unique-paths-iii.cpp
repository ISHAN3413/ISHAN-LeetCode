class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rs = 0;
        int sx , sy;
        for(int i = 0;i<n; i++){
            for(int j = 0;j<m ; j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j]==0){
                    rs++;
                }
            }
        }
        return f(grid,sx,sy,rs+1);
    }
    int f(vector<vector<int>>& grid ,int i , int j ,int rs){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||grid[i][j]==-1){
            return 0;
        }
        if(grid[i][j]==2){
            if(rs==0)return 1;
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        int a[4] = {1 , 0 ,-1 , 0};
        int b[4] = {0 , 1 , 0 , -1};
        int ans = 0;
        for(int k = 0 ; k < 4 ; k++){
            ans+=f(grid , i+a[k] , j + b[k] , rs-1);
        }
        grid[i][j] = temp;
        return ans;
    }
};