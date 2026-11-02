class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        vector<int> dp(n+1 , -1);
        return f(dp,n);
    }
    int f(vector<int>&dp , int n){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = f(dp,n-1)+f(dp,n-2);
    }
    
};