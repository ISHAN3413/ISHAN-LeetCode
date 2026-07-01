class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> can;
        vector<vector<int>> ans;
        f(nums,0,ans,can);
        return ans;
    }
    void f(vector<int>&nums , int i , vector<vector<int>>&ans , vector<int>&can){
        if(i==nums.size()){
            if(s.find(can)==s.end()){
                ans.push_back(can);
                s.insert(can);
            }
            return;
        }
        can.push_back(nums[i]);
        f(nums,i+1,ans,can);
        can.pop_back();
        f(nums,i+1,ans,can);
        return;
    }
};