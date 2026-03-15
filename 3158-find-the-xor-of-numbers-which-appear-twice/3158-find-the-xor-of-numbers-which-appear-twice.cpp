class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        std::unordered_map<int,int> m;
      
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==2){
               a.push_back(i.first);
            }
        }
        if(a.size()==0)return 0;
        int k=a[0];
        for(int i=1;i<a.size();i++){
            k=k^a[i];
        }
        return k;
    }
};