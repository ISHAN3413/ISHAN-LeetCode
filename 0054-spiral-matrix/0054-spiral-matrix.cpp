class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        bool l = false;
        bool r = true;
        bool u = false;
        bool d = false;
        int i = 0;
        int j = 0;
        for(int k = 0 ; k< n*m ;k++){
            ans.push_back(matrix[i][j]);
            vis[i][j] = 1;
            if(r){
                if(j+1<m && !vis[i][j+1]){
                    j++;
                }
                else{
                    r=false;
                    d=true;
                    i++;
                }
            }
            else if(l){
                if(j-1>=0 && !vis[i][j-1]){
                    j--;
                }
                else{
                    l=false;
                    u=true;
                    i--;
                }
            }
            else if(u){
                if(i-1>=0 && !vis[i-1][j]){
                    i--;
                }
                else{
                    u=false;
                    r=true;
                    j++;
                }
            }
            else if(d){
                if(i+1<n && !vis[i+1][j]){
                    i++;
                }
                else{
                    d=false;
                    l=true;
                    j--;
                }
            }
            
        }
        return ans;
    }
};