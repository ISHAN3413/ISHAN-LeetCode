class Solution {
public:
    string largestOddNumber(string nums) {
        string ans = "";
        string a = "";
        for(int i = 0;i<nums.length();i++){
            a+=nums[i];
            if((nums[i]-'0')%2 !=0){
                ans=a;
            }
        }
        return ans;
    }
};