class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       if(nums.size()==1){
        if(nums[0]==1)return 2;
        return 1;
       }
       vector<int> b;
       b=removedub(nums);
        int n=b.size();
        for(int i=0;i<b.size();i++){
            if(b[i]<=0)b[i]=INT_MAX-1;
        }
        std::sort(b.begin(),b.end());
        int maxi=b[b.size()-1];
        if(maxi==INT_MAX)maxi-=1;
        for(int i=1;i<maxi+1;i++){
            if(b[i-1]!=i)return i;
        }
        return {maxi+1};
     }
     private:
     vector<int> removedub(vector<int> a){
        vector<int> b;
        std::unordered_map<int,int> m;

        for(int i=0;i<a.size();i++){
            m[a[i]]++;
     }
     for(auto i:m){
        b.push_back(i.first);
     }
     return b;
     }
};