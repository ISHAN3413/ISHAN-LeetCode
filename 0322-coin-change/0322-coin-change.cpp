class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));
        int ans =  f(coins , amount , 0 ,dp);
        if(ans == INT_MAX)return -1;
        return ans;
    }
    int f(vector<int> &coins , int am , int i , vector<vector<int>> &dp){
        if(am <= 0)return 0;
        if(i >= coins.size())return INT_MAX;
        if(dp[i][am]!=-1)return dp[i][am];
        int pick = INT_MAX;
        if(coins[i]<=am){
            int res =  f(coins , am-coins[i] , i ,dp);
            if(res!=INT_MAX)pick = 1+res;
        }
        int notpick = f(coins , am , i+1 ,dp);
        return dp[i][am] = min(pick , notpick);
    }
};