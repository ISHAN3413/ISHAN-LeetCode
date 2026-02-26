class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        int cn = cuts.size();
        vector<vector<int>> dp(cn+1 , vector<int>(cn+1 , -1) );
        cuts.insert(cuts.begin() , 0);
        cuts.push_back(n);
        return f(1 ,cn,cuts,dp );
    }
    int f(int i , int j , vector<int>& cuts , vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i ; ind<=j;ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(i , ind-1 ,cuts ,dp) + f(ind+1 , j ,cuts,dp);
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
};