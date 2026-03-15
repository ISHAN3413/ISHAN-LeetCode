class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)return 1;
        int n=mat.size();
        int i,j,k;
        for(i=0;i<3;i++){
            rotate(mat);
            if(mat==target)return 1;
        }
        return 0;
    }
    private:
    void rotate(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};