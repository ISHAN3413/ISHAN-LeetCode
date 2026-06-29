class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums,0,ans);
        return ans;
    }
    void f(vector<int>&nums , int ind , vector<vector<int>>&ans){
        if(ind == nums.size()){
            if(s.find(nums)==s.end()){
                ans.push_back(nums);
                s.insert(nums);
            }
            return;
        }
        for(int i = ind ; i<nums.size();i++){
            swap(nums[i],nums[ind]);
            f(nums,ind+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
};