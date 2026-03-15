class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        std::unordered_map<int,int> m;
        vector<int> a;
        int maxi=0;
        
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)m[nums[i]]++;
        }
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        for(auto i:m){
           if(i.second==maxi)a.push_back(i.first);
        }
        if(a.size()==0)return -1;
        if(a.size()==1)return a[0];
        int mini=a[1];
            for(int i=0;i<a.size();i++){
                mini=min(mini,a[i]);
            }
        return mini;
    }
};