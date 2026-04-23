class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int k = 2;
        double p = (double)poured;
        vector<vector<double>> dp(query_row+1);
        dp[0] = {p};
        for (int i = 1; i <= query_row; i++) {
            vector<double>d(k , 0);
            for (int j = 0; j < k; j++) {
                double left = 0;
                double right = 0;
                if(j-1>=0){
                    left = max(0.0 , (dp[i-1][j-1] -1) / 2.0);
                }
                if(j<dp[i-1].size()){
                    right = max(0.0 , (dp[i-1][j] - 1)/2.0);
                }
                d[j] +=(left+right);
            }
            dp[i] = d;
            k++;
        }
        return min(1.0 , dp[query_row][query_glass]);
    }
};