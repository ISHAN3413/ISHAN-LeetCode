class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
       for(auto i:m){
        if(i.second>(nums.size()-1)/2){
            return i.first;
        }
       }
       return 0;
    }
};