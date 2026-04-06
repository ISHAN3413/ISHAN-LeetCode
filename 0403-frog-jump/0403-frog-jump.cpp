class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1)return false;
        vector<vector<int>> dp(n , vector<int>(n+1,-1));
        return f(stones , 1 , 1,dp);
    }
    bool f(vector<int>& stones , int k , int pre , vector<vector<int>> &dp){
        if(k == stones.size()-1)return 1;
        if(dp[k][pre]!=-1)return dp[k][pre];
        for(int i = pre-1 ; i<=pre+1 ; i++){
            if(i<=0)continue;
            int target = stones[k]+i;
            for(int j = k+1 ; j< stones.size() ; j++){
                if(stones[j] == target){
                    if(f(stones , j , i,dp))return dp[k][pre] = 1;
                }
                if(stones[j]>target)break;
            }
        }
        return dp[k][pre] = 0;
    }
};