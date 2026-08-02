class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(s1,s2,0,0,dp);
    }
    int f(string &s1 , string &s2 , int i , int j ,vector<vector<int>>&dp){
        int a = 0;
        if(i>=s1.size()){
            while(j<s2.size()){
                a+=s2[j];
                j++;
            }
            return a;
        }
        if(j>=s2.size()){
            a=0;
            while(i<s1.size()){
                a+=s1[i];
                i++;
            }
            return a;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return f(s1,s2,i+1,j+1,dp);
        int l = s1[i]+f(s1,s2,i+1,j,dp);
        int r = s2[j]+ f(s1,s2,i,j+1,dp);
        return dp[i][j] = min(l,r);
    }
};