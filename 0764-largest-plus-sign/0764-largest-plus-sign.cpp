class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        unordered_set<int> s;
        for(int i = 0;i<mines.size();i++){
            s.insert(mines[i][0]*n+mines[i][1]);
        }
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n , 0));
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                count = (s.find(i*n + j)!=s.end())?0:count+1;
                dp[i][j] = count;
            }
            count = 0;
            for(int j = n-1 ; j>=0 ;j--){
                count = (s.find(i*n + j)!=s.end())?0:count+1;
                dp[i][j] = min(dp[i][j] , count);
            }
        }

        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                count = (s.find(j*n + i)!=s.end())?0:count+1;
                dp[j][i] = min(dp[j][i] , count);
            }
            count = 0;
            for(int j = n-1 ; j>=0 ;j--){
                count = (s.find(j*n + i)!=s.end())?0:count+1;
                dp[j][i] = min(dp[j][i] , count);
                ans = max(dp[j][i] , ans);
            }
        }
        return ans;

    }
};