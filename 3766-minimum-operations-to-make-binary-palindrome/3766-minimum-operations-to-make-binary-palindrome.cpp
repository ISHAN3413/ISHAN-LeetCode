class Solution {
public:
    bool isBP(int n){
        if(n<0)return false;
        if(n==0)return true;
        string num;
        while(n>0){
            num.push_back(char('0' + (n&1)));
            n>>=1;
        }
        int i = 0;
        int j = num.length()-1;
        while(i<j){
            if(num[i] != num[j])return false;
            i++;
            j--;
        }
        return true; 
    }
    vector<int> minOperations(vector<int>& nums){
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(isBP(nums[i])){
                ans.push_back(0);
                continue;
            }
            int j=1;
            while(true){
                if(isBP(nums[i]+j)){
                    ans.push_back(j);
                    break;
                }
                if(nums[i]-j>=0 && isBP(nums[i]-j)){
                    ans.push_back(j);
                    break;
                }
                j++;
            }
            
        }
        return ans;
    }
};