class Solution {
public:
    bool divideArray(vector<int>& nums) {
        std::unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i: map){
            if(i.second%2!=0)return false;
        }
        return true;
    }
};