class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0 )return false;
        unordered_map<int,int> count , tails;
        sort(nums.begin(),nums.end());
        for(int i:nums)count[i]++;
        for(int i:nums){
            if(count[i]==0)continue;
            for(int j = 0;j<k;j++){
                int curr = i+j;
                if(count[curr]>0){
                    count[curr]--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};