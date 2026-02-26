class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int left = (j > 0) ? prev[j - 1] : INT_MAX;
                int right = (j < m - 1) ? prev[j + 1] : INT_MAX;
                curr[j] = matrix[i][j] + min({up, left, right});
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};