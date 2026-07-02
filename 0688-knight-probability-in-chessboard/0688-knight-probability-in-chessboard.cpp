class Solution {

public:
   
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>>dp(n , vector<vector<double>>(n,vector<double>(k+1 , -1.0)));
        return knightProbabilit(n,k,r,c,dp);
    }

    double knightProbabilit(int n, int k, int r, int c ,vector<vector<vector<double>>>&dp ){
        if(r<0 || c<0 || r>=n || c>=n){
            return 0.0;
        }
        if(k==0){
            return 1.0;
        }
        if(dp[r][c][k]!=-1.0)return dp[r][c][k];

        double s = 0.0;
        s+= knightProbabilit(n, k - 1, r - 2, c - 1,dp);
        s+= knightProbabilit(n, k - 1, r - 2, c + 1,dp);
        s+= knightProbabilit(n, k - 1, r - 1, c - 2,dp);
        s+= knightProbabilit(n, k - 1, r - 1, c + 2,dp);
        s+= knightProbabilit(n, k - 1, r + 1, c - 2,dp);
        s+= knightProbabilit(n, k - 1, r + 1, c + 2,dp);
        s+= knightProbabilit(n, k - 1, r + 2, c - 1,dp);
        s+= knightProbabilit(n, k - 1, r + 2, c + 1,dp);
        return dp[r][c][k] = s/8;
    }
};
