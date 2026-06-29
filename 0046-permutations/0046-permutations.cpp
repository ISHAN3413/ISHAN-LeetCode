class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<int>vis(nums.size(),false);
        vector<vector<int>> ans;
        f(nums,curr,vis,ans);
        return ans;
    }
    void f(vector<int>&nums , vector<int>&curr,vector<int>&vis , vector<vector<int>> &ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i =0 ;i <nums.size();i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = true;
                f(nums,curr,vis,ans);
                vis[i]=false;
                curr.pop_back();
            }
        }
    }
};