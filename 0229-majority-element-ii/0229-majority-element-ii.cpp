class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> m;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>nums.size()/3){
                a.push_back(i.first);
            }
        }
        return a;
    }
};