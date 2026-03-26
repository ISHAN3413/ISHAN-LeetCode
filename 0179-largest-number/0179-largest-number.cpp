class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &a , int &b){
            string ai = to_string(a);
            string bi = to_string(b);
            string aj = ai+bi;
            string bj = bi+ai;
            if(aj>bj)return true;
            else return false;
        });
        string ans = "";
        for(int i = 0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        if(ans[0]=='0')return "0";
        return ans;
    }
};