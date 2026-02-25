class Solution {
public:
    static const int mod = 1e9 + 7;
    int countPaths(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
         vector<vector<int>> dp(n , vector<int>(m,-1));
        int ans = 0;
        for(int i = 0 ; i<n ;i++){
            for(int j = 0;j<m ;j++){
                ans = (ans + f(i,j,matrix,dp))%mod;
            }
        }
        return ans;
    }
    int f(int i , int j , vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int mod = 1e9 +7;
        if(dp[i][j]!=-1)return dp[i][j];
        int n = matrix.size();
        int m = matrix[0].size();
        int nrow[] = {-1 , 0 , 1 ,0};
        int ncol[] = {0 , 1 , 0 , -1};
        int ans = 0;
        int a = 1;
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        for(int k = 0;k<4;k++){
            int row = i+nrow[k];
            int col = j+ncol[k];
            if(row>=0 && col>=0 && row<n && col<m && matrix[i][j]<matrix[row][col]){
                a=(a+f(row , col ,matrix,dp))%mod;
            }
        }
         return dp[i][j]=a;
    }
};