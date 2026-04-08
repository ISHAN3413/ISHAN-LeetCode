class Solution {
public:
    int n;
    vector<int> suffix;
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        suffix.resize(n);
        suffix[n-1] = piles[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i]= suffix[i+1] + piles[i];
        }
        return f(0,1,dp);
    }
    int f(int i , int m ,vector<vector<int>> &dp ){
        if(i>=n)return 0;
        if(2*m>=n-i)return suffix[i];
        if(dp[i][m]!=-1)return dp[i][m];
        int res = 0;
        for(int X = 1 ; X<=2*m ; X++){
            res = max(res , suffix[i]- f(i+X , max(X , m),dp));
        }
        return dp[i][m]=res;
    }
};