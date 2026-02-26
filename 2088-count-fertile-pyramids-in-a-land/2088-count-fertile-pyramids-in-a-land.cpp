class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m ;j++){
                int h = dfs(i , j , grid,dp);
                if(h>=2)ans+=(h-1);
            }
        }
        reverse(grid.begin() , grid.end());
         vector<vector<int>> dp1(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m ;j++){
                int h = dfs(i , j , grid,dp1);
                if(h>=2)ans+=(h-1);
            }
        }
        return ans;
    }
    int dfs(int i , int j , vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>=n || j<0 || j>=m||grid[i][j] == 0)return dp[i][j]= 0;
        if(i+1>=n||j-1<0||j+1>=m)return dp[i][j]=1;
        if(grid[i+1][j] ==0 || grid[i+1][j-1] == 0||grid[i+1][j+1]==0)return dp[i][j]=1;
        return dp[i][j]= 1+min(dfs(i+1 , j ,grid ,dp) ,min(dfs(i+1 , j-1 , grid,dp) , dfs(i+1 , j+1 , grid,dp)) );
    }
};