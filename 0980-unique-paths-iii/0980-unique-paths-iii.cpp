class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si,sj,rs=0;
        for(int i = 0 ;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    si = i;
                    sj = j;
                }
                else if(grid[i][j]==0){
                    rs++;
                }
            }
        }
        return f(grid,si,sj,rs+1);
    }
    int f(vector<vector<int>>&grid , int i , int j , int s){
        if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size()||grid[i][j]==-1){
            return 0;
        }
        if(grid[i][j]==2){
            if(s==0)return 1;
            return 0;
        }
        int d[] = {1 , 0 , -1 ,0};
        int r[] = {0 , 1 , 0 , -1};
        int ans = 0;
        int temp = grid[i][j];
        grid[i][j] =-1;
        for(int k = 0;k<4;k++){
            ans += f(grid,i+d[k] , j+r[k] , s-1);
        }
        grid[i][j] = temp;
        return ans;
    }
};