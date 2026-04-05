class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        for(int i = 0 ; i<= (n+m-2) ; i++){
            if(i%2 == 0){
                int r = (i<n)?i:n-1;
                int c = i-r;
                while(r >= 0 && c<m){
                    ans.push_back(mat[r][c]);
                    r--;
                    c++;
                }
            }
            else{
                int c = (i<m)?i:m-1;
                int r = i-c;
                while(r<n && c>=0){
                    ans.push_back(mat[r][c]);
                    r+=1;
                    c-=1;
                }
            }
        }
        return ans;
    }
};