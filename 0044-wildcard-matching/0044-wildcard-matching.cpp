class Solution {
public:
    bool isMatch(string s, string p) {
        int i = s.length();
        int j = p.length();
        vector<vector<int>> dp(i , vector<int>(j , -1));
        return f(i-1 , j-1 , s, p , dp);
    }
    bool f(int i , int j , const string &s ,const string &p , vector<vector<int>> &dp){
        if(i<0 && j<0)return true;
        if(i<0){
            for(int k = j;k>=0 ; k--){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(j<0){
            return false;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if((s[i] == p[j] )||( p[j] == '?')){
            return dp[i][j] =  f(i-1 , j-1 , s , p , dp);
        }
        if(p[j] == '*'){
            return dp[i][j] =   (f(i-1 , j , s , p,dp)||f(i , j-1 , s , p,dp));
        }
        return dp[i][j] =  false;
    }
};