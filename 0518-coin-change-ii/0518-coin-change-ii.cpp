class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n , vector<int>(amount+1 , -1));
        return h( n-1 ,coins , amount ,dp);
    }
    int h(int ind, vector<int>& coins , int target , vector<vector<int>> &dp){
        if(ind==0){
            return( target%coins[0] ==0);
        }
        if(dp[ind][target]!=-1)return dp[ind][target]; 
        int nottake = h(ind-1 ,coins , target ,dp);
        int take = 0;
        if(coins[ind]<=target) take = h(ind,coins , target - coins[ind] ,dp);
        return dp[ind][target] = take + nottake ;
    }
};