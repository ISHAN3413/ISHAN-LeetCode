class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2 , vector<int>(3,-1)));
        return f(prices,0,false,2,dp);
    }
    int f(vector<int>& prices , int i , bool isb, int c,vector<vector<vector<int>>>& dp){

        if(i>=prices.size() || c==0)return 0;
        int ans = 0;
        if(dp[i][isb][c]!=-1)return dp[i][isb][c];
        if(!isb){
            ans = max(ans , -prices[i]+f(prices,i+1,true,c,dp));
            ans = max(ans , f(prices,i+1,false,c,dp));
        }
        else{
            ans  = max(ans ,prices[i]+f(prices , i+1 , false,c-1,dp));
            ans = max(ans , f(prices , i+1 , true , c,dp));
        }
        return dp[i][isb][c] = ans;
    }
};