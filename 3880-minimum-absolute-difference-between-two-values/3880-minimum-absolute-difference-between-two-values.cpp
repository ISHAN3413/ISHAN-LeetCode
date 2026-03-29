class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int alas = -1;
        int blas = -1;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                alas = i;
                if(blas!=-1){
                    ans = min(ans , abs(alas - blas));
                }
            }
            else if(nums[i]==2){
                blas = i;
                if(alas !=-1){
                    ans = min(ans , abs(alas - blas));
                }
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};