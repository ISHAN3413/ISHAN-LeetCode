class Solution {
public:
    int modu = 1e9 +7;
    int findPaths(int m, int n, int mm, int i, int j) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(mm+1 , -1)));
        return f(m,n,mm,i,j,dp);
    }
    int f(int m , int n , int mm , int i , int j, vector<vector<vector<int>>> &dp){
        if(i>=m || j>=n || i<0 || j<0){
            return 1;
        }
        if(mm<=0){
            return 0;
        }
        if(dp[i][j][mm]!=-1)return dp[i][j][mm];
        long long ans = 0;
        ans+=f(m,n,mm-1,i-1,j,dp);
        ans+=f(m,n,mm-1,i+1,j,dp);
        ans+=f(m,n,mm-1,i,j-1,dp);
        ans+=f(m,n,mm-1,i,j+1,dp);

        return dp[i][j][mm] = ans%modu;
    }
};