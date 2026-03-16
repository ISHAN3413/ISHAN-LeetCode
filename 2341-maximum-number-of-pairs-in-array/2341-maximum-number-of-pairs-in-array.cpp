class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto a:map){
           ans[0]+=a.second/2;
           ans[1]+=a.second%2;
        }
        return ans;
    }
};