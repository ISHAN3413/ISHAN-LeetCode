class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row;
        vector<int> col;
        for(int i = 0;i<grid.size();i++){
            int maxi = 0;
            for(int j = 0;j<grid.size();j++){
                maxi = max(maxi , grid[i][j]);
            }
            row.push_back(maxi);
        }
        for(int i = 0;i<grid.size();i++){
            int maxi = 0;
            for(int j = 0;j<grid.size();j++){
                maxi = max(maxi , grid[j][i]);
            }
            col.push_back(maxi);
        }
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                ans+=(min(row[i],col[j]) - grid[i][j]);
            }
        }
        return ans;
    }
};