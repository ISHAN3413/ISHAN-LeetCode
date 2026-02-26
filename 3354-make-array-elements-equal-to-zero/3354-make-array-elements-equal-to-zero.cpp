class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int tos = 0;
        for(int i=0 ;i<nums.size();i++){
            tos+=nums[i];
        }
        int ls = 0;
        int rs = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ls+=nums[i];
            if(nums[i]==0){
                rs = tos - ls;
                if(ls == rs){
                    ans+=2;
                }
                if(ls == rs-1 || rs == ls-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};