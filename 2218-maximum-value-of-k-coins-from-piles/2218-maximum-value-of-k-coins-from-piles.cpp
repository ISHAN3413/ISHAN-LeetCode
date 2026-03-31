class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1 , vector<int>(k+1,-1));
        return f(0 , k , piles ,dp);
        
    }
    int f (int i , int k , vector<vector<int>>& piles , vector<vector<int>> &dp){
        if(k==0)return 0;
        if(i == piles.size())return 0;
        if(dp[i][k] !=-1)return dp[i][k];
        int ans =0 ;
        int sum = 0;
        for(int x = 0 ; x<=(min((int)piles[i].size() , k));x++){
            if(x>0)sum+=piles[i][x-1];
            ans = max(ans , sum+f(i+1 , k-x ,piles ,dp));
        }
        return dp[i][k] = ans;
    }
};