class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.length()<t.length())return 0;
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        return f(s,t,0,0,dp);
    }
    int f(string &s , string &t , int i , int j , vector<vector<int>>&dp){
        if(i>=s.length()){
            if(j>=t.length())return 1;
            return 0;
        }
        if(j>=t.length()){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans+=f(s,t,i+1,j+1,dp);
            ans+=f(s,t,i+1 , j,dp);
        }
        else{
            ans+=f(s,t,i+1,j ,dp);
        }
        return dp[i][j] = ans;
    }
};