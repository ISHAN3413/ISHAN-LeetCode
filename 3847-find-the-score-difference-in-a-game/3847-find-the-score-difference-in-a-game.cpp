class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans = 0;
        bool act = 1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2!=0 ){
                act = !act;
            }
            if((i+1)%6==0){
                    act = !act;
                }
            if(act){
                ans+=nums[i];
            }
            if(!act){
                ans-=nums[i];
            }
        }
        return ans;
    }
};