class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1)return mat[0][0];
        int row=mat.size();
        int k=0;
        for(int i=0;i<row;i++){
           k=k+mat[i][i];
        }
        int j=0;
        for(int i=row-1;i>=0;i--){
            k=k+mat[i][j];
            j++;
        }
       
       if(row%2!=0){
        k-=mat[(row/2)][(row/2)];
       }
        return k;
    }
};