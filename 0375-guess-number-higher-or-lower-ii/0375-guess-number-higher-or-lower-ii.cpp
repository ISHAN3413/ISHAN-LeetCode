class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1 ,vector<int>(n+1 , -1));
        return f(1,n,dp);
    }
    int f(int start , int end,vector<vector<int>> & dp){
        if(start>=end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        if(start>end)return INT_MIN;
        int ans = INT_MAX;
        for(int i = start ; i<=end ; i++ ){
            int a = i +max(f(start , i-1 ,dp) ,f(i+1,end,dp));
            ans = min(ans,a);
        }
        return dp[start][end] =  ans;
    }
};