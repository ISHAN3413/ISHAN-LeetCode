class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n , vector<int>(n , 0));
        vector<vector<int>> memo(n , vector<int>(n,INT_MAX));
        return f(grid , 0 , 0 , grid[0][0] , vis ,memo);
    }

    int f(vector<vector<int>>& grid , int  i , int j ,int t ,  vector<vector<int>> &vis , vector<vector<int>>& memo ){
        if(t>=memo[i][j]){
            return INT_MAX;
        }
        memo[i][j] = t;
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return t;
        }
        vis[i][j] = 1;
        int a[4] = {1 , 0 , -1 , 0};
        int b[4] = {0 , 1 , 0 , -1};
        int ans = INT_MAX;
        for(int k = 0 ; k < 4 ; k++){
            int ni = i + a[k];
            int nj = j + b[k];
            
            if(ni>= 0 && nj >= 0 && ni<grid.size() && nj < grid[0].size() && !vis[ni][nj]){
                ans = min(ans , f(grid , ni , nj , max(t , grid[ni][nj]) , vis ,memo));
            }
        }
        vis[i][j] = 0;
        return ans;
    }
};