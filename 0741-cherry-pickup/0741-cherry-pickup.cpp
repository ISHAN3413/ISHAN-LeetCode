class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
       vector<vector<vector<int>>> dp(n ,vector<vector<int>>(n ,vector<int>(n,-1)));
        int result = f(grid, 0, 0, 0,dp);
        return max(0, result);
    }

    int f(vector<vector<int>>& grid, int r1, int c1, int r2, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int c2 = r1 + c1 - r2; 

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e8;

       if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
            if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int next = max({
            f(grid, r1 + 1, c1, r2 + 1 ,dp), 
            f(grid, r1, c1 + 1, r2,dp),    
            f(grid, r1 + 1, c1, r2,dp),    
            f(grid, r1, c1 + 1, r2 + 1,dp)
        });

        return dp[r1][c1][r2] =  cherries + next;
    }
};
