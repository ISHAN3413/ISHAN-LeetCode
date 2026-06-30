class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        return f(grid,0,0,0);
    }
    bool f(vector<vector<int>>& grid , int i , int j , int val){
        int n = grid.size();
        if(i>=grid.size() || i<0 || j<0 || j>=grid.size() || grid[i][j]!=val)return false;
        if(grid[i][j] ==n*n-1)return true;

        return f(grid,i-2,j+1,val+1)||f(grid,i-1,j+2,val+1)||f(grid,i+1,j+2,val+1)||f(grid,i+2,j+1,val+1)||f(grid,i+2,j-1,val+1)||f(grid,i+1,j-2,val+1)||f(grid,i-1,j-2,val+1)||f(grid,i-2,j-1,val+1);
    }
};