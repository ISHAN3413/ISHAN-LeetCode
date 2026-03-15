class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> a;
        std::unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==1)a.push_back(i.first);
        }
        return a;
    }
};