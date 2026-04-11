class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0')
            return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                int res = dp[i + 1];
                if (i + 1 < s.length() &&
                    (s[i] == '1' || (s[i] == '2' && ((s[i + 1] <= '6') &&(s[i + 1] >= '0'))))) {
                    res += dp[i + 2];
                }
               dp[i] = res; 
            }
            
        }
        return dp[0];
    }
    int f(string s, int i, vector<int>& dp) {
        if (i == s.length())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int res = f(s, i + 1, dp);
        if (i + 1 < s.length() &&
            (s[i] == '1' ||
             (s[i] == '2' && ((s[i + 1] <= '6') && (s[i + 1] >= '0'))))) {
            res += f(s, i + 2, dp);
        }
        return dp[i] = res;
    }
};