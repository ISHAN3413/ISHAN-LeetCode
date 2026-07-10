class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        return f(s,p,0,0,dp);
    }
    bool f(string &s , string &p , int i , int j,vector<vector<int>> &dp){
        if(i>=s.length()){
            while(j<p.length()){
                if(p[j]!='*')return false;
                j++;
            }
            return true;
        }
        if(j>=p.length()){
            return false;
        }
        if(i==s.length() &&j==p.length())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] =  f(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] =  f(s,p,i+1,j,dp)||f(s,p,i,j+1,dp)||f(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = false;
    }
};