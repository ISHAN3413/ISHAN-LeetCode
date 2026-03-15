class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        std::unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==1)return i.first;
        }
        return {};
    }
};