class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1 , 0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            int total = 0;
            for(int j=1;j<=i;j++){
                int left = dp[j-1];
                int right = dp[i-j];
                total+=left*right;
            }
            dp[i]=total;
        }
        return dp[n];
    }
};