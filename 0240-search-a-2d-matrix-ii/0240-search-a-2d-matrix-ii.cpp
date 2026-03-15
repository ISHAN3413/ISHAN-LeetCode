class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int cols=mat[0].size();
        for(int col=0;col<cols;col++){
            if(mat[0][col]<=target && mat[mat.size()-1][col]>=target){
                if(binary(mat,col,target))return true;
            }
        }
        return false;
    }
    private:
    bool binary(vector<vector<int>>& mat,int col,int target){
        int start=0;
        int end=mat.size()-1;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(mat[mid][col]==target)return true;
            else if(mat[mid][col]<target)start=mid+1;
            else end=mid-1;
        }
        return false;
    }
};