class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        int rmax = 0;
        for(int i = 0;i<nums.size();i++){
            string s = to_string(nums[i]);
            int range = 0;
            
            char maxi = s[0];
            char mini = s[0];
            for(int j = 0; j <s.length();j++){
                if(s[j]>maxi)maxi=s[j];
                if(s[j]<mini)mini=s[j];
                
            }
            range = maxi-mini;
            if(range>rmax){
                ans = 0;
                rmax = range;
            }
            if(range == rmax)ans+=nums[i];
        }
        return ans;
    }
};