class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        vector<vector<vector<int>>> dp(11 , vector<vector<int>>(3 , vector<int>(10,-1)));
        return solve(s,0,1,0,dp);
    }
    int solve(string& s , int ind , bool tight , int coo ,vector<vector<vector<int>>> &dp){
        if(ind == s.size()){
            return coo;
        }
        if(dp[ind][tight][coo]!=-1)return dp[ind][tight][coo];
        int res = 0;
        int up = (tight==1) ?s[ind]-'0' :9;
        int lb = 0;
        for(int i = lb ; i<=up ; i++){
            res+=solve(s , ind+1 ,( tight && i==up) , coo+(i==1) , dp);
        }
        return dp[ind][tight][coo] =  res;
    }
};