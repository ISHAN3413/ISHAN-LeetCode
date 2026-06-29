class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int>curr;
        // vector<int>vis(nums.size(),false);
        vector<vector<int>> ans;
        // f(nums,curr,vis,ans);
        permutation(nums,0,ans);
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
    void permutation(vector<int>&nums , int ind , vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(nums);
        }
        for(int i= ind ; i<nums.size();i++){
            swap(nums[ind],nums[i]);
            permutation(nums,ind+1,ans);
            swap(nums[ind],nums[i]);
        }
    }
};