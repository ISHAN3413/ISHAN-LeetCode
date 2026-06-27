class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int>comb;
       vector<vector<int>>ans;
       f(k,n,1,comb,ans);
       return ans;
    }
    void f(int k , int n , int i,vector<int>&comb,vector<vector<int>> &ans){
        if(k==0 && n==0){
            ans.push_back(comb);
            return;
        }
        if(i>9 || k<0){
            return;
        }
        comb.push_back(i);
        f(k-1 , n-i , i+1 , comb,ans);
        comb.pop_back();
        f(k,n,i+1,comb,ans);
    }
};