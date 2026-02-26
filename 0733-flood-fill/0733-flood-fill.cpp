class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inico = image[sr][sc];
        vector<vector<int>> ans = image;
        int a[]={-1 , 0 ,1 , 0};
        int b[]={0,1,0,-1};
        dfs(image,ans,inico,color,sr,sc,a,b);
        return ans;
    }
    void dfs(vector<vector<int>>& image,vector<vector<int>> &ans ,int inico, int newclr , int sr,int sc, int a[],int b[]){
        ans[sr][sc] = newclr;
        int n = ans.size();
        int m = ans[0].size();
        for(int i = 0;i<4;i++){
            int newro = sr+a[i];
            int newco = sc+b[i];
            if(newro>=0 && newro<n && newco>=0 && newco<m && image[newro][newco]==inico && ans[newro][newco]!=newclr){
            dfs(image,ans ,inico, newclr ,newro , newco ,a,b);  
            }
        }
    }
};