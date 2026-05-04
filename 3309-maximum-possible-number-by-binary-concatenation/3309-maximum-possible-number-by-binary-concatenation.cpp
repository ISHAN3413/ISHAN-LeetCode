class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        maxi(nums , 0 , ans);
        return ans;
    }
    void maxi(vector<int>& nums , int ind , int &ans){
        if(ind == nums.size()){
            int a = concatenatedBinary(nums);
            ans=max(ans,a);
            return;
        }
        for(int i = ind ; i< nums.size();i++){
            swap(nums[ind] , nums[i]);
            maxi(nums,ind+1,ans);
            swap(nums[ind],nums[i]);
        }
    }
    int concatenatedBinary(vector<int>& n) {
        long long ans = 0;
        long long pot = 1;
        for(int i = 0; i<n.size();i++){
            int a = n[i];
            while(a!=0){
                if(a&1){
                   ans = (ans+pot);
                }
                pot = (pot*2 );
                a>>=1;
            }
        }
        return (int)ans;
    }
};