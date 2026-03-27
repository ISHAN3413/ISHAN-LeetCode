class Solution {
public:
    string largestOddNumber(string nums) {
        vector<pair<int,int>> h;
        int maxnum = -1;
        int maxin = -1;
        int j = 0;
        for(int i = nums.length()-1;i>=0;i--){
            int a = nums[i]-'0';
            if(a%2 != 0){
                maxin = i;
                break;
            }
        }
        string ans = "";
        for(int i =0;i<=maxin;i++){
            ans+=nums[i];
        }
        return ans;
    }
};