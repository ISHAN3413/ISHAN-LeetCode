class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<vector<int>> h;
        for(int i = 0 ; i<mat.size() ; i++){
            for(int j = 0 ; j<mat[0].size() ; j++){
                if(mat[i][j] == 0)h.push_back({i , j});
            }
        }
        for(int i = 0 ; i < h.size() ; i++){
            for(int j = 0;j<mat.size();j++){
                mat[j][h[i][1]] = 0;
            }
            for(int k = 0;k<mat[0].size();k++){
                mat[h[i][0]][k] = 0;
            }
        }
    }
};