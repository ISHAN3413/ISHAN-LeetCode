class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mini =INT_MAX;
        vector<vector<int>> dp(n ,vector<int>(m,-1));
        for(int j = 0 ; j<m;j++){
            mini = min(mini , f(n-1 , j ,grid ,dp ));
        }
        return mini;
    }
    int f( int i , int j ,vector<vector<int>>& grid ,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i==0)return grid[0][j];
        if(j<0 || j>=m)return 1e8;
        if(dp[i][j]!=-1)return dp[i][j];
        int res = 1e8;
        for(int k =0 ;k<m;k++){
            if(k==j)continue;
            res = min(res , f(i-1 , k ,grid ,dp));
        }
        return dp[i][j] = res + grid[i][j];
    }
};