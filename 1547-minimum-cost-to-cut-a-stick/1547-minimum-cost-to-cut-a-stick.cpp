class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int cn = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(cn+2,vector<int>(cn+2,-1));
        sort(cuts.begin() , cuts.end());
        return f(cuts,1 ,cn ,dp);
    }
    int f(vector<int>&cuts ,int l , int r ,vector<vector<int>>&dp){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int mini = INT_MAX;
        for(int i = l;i<=r;i++){
            int cost = cuts[r+1] - cuts[l-1] + f(cuts , l , i-1,dp) + f(cuts,i+1,r,dp);
            if(cost<mini)mini = cost;
        }
        return dp[l][r] = mini;
    }
};