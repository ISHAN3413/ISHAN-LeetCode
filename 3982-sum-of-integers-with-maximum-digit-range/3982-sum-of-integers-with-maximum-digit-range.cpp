class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ranmaxi = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            string s = to_string(nums[i]);
            char maxi = s[0];
            char mini = s[0];
            for(int j = 0;j<s.length();j++){
                if(s[j]>maxi)maxi = s[j];
                if(s[j]<mini)mini = s[j];
            }
            int ran = maxi -mini;
            
            if(ranmaxi == ran)ans+=nums[i];
            else if(ran>ranmaxi) ans=nums[i];


            ranmaxi = max(ranmaxi , ran);  
        }
        return ans;
    }
};