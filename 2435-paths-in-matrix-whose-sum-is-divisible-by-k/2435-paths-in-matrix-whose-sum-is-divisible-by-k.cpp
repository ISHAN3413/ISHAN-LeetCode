class Solution {
public:
int mod = 1e9 +7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int sum = grid[0][0];
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return f(m-1,n-1,grid ,k ,0 ,dp);
    }
    int f(int r ,int c , vector<vector<int>>& grid , int k ,int sum , vector<vector<vector<int>>> &dp){
        if(r<0 && c<0)return 0;
        sum = (sum+grid[r][c])%k;
        if(r==0 && c==0 && sum%k == 0)return 1 ;
        if(dp[r][c][sum] != -1)return dp[r][c][sum];
        int up = 0;
        int dow =0 ;
        if(r>0) up = f(r-1 , c ,grid ,k , sum ,dp);
        if(c>0) dow= f(r , c-1 , grid ,k, sum ,dp);
        return dp[r][c][sum] = (up + dow)%mod;
    }
};