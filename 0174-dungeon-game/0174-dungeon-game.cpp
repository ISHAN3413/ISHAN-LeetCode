class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n = dun.size();
        int m = dun[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return f(dun,0,0,dp);
    }
    int f(vector<vector<int>>& dun , int i , int j,vector<vector<int>>&dp){
        int n = dun.size();
        int m = dun[0].size();

        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1 && j==m-1){
            return max(1 , 1-dun[i][j]);
        }
        int need = min(f(dun,i+1,j,dp),f(dun,i,j+1,dp));

        return dp[i][j] =  max(1 , need -dun[i][j]);
    }
};