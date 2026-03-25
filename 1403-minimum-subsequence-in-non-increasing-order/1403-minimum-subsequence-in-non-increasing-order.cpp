class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a , int &b){
            return a>b;
        });
        vector<int> h = nums;
        for(int i = 1;i<h.size();i++){
            h[i]+=h[i-1];
        }
        vector<int> ans;
        for(int i = 0;i<h.size();i++){
            ans.push_back(nums[i]);
            if(h[i]>(h[h.size()-1]-h[i]))break;
        }
        return ans;
    }
};