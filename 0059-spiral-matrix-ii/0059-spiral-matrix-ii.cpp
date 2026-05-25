class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n,0));
        bool l = false;
        bool r = true;
        bool u = false;
        bool d = false;
        int i = 0;
        int j = 0;
        for(int k = 1;k<=n*n ; k++){
            ans[i][j] = k;
            if(r){
                if(j+1<n && ans[i][j+1]==0){
                    j++;
                }
                else{
                    r=false;
                    d=true;
                    i++;
                }
            }
            else if(d){
                if(i+1<n && ans[i+1][j]==0){
                    i++;
                }
                else{
                    d=false;
                    l=true;
                    j--;
                }
            }
            else if(l){
                if(j-1>=0 && ans[i][j-1]==0){
                    j--;
                }
                else{
                    l=false;
                    u=true;
                    i--;
                }
            }
            else if(u){
                if(i-1>=0 && ans[i-1][j]==0){
                    i--;
                }
                else{
                    u=false;
                    r=true;
                    j++;
                }
            }
        }
        return ans;
    }
};