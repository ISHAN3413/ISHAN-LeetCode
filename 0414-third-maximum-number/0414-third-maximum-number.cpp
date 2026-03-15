class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::unordered_map<int,int> m;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            a.push_back(i.first);
        }
        std::sort(a.begin(),a.end(),std::greater<int>());
        int maxi=a[0];
        if(a.size()<3){
            for(int i=0;i<a.size();i++){
                maxi=max(maxi,a[i]);
            }
            return maxi;
        }
        return a[2];
    }
};