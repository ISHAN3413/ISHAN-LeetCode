class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count , tails;
        for(int i:nums)count[i]++;
        for(int i :nums){
            if(count[i]==0)continue;
            if(tails[i-1]>0){
                count[i]--;
                tails[i-1]--;
                tails[i]++;
            }
            else if(count[i+1]>0 && 0<count[i+2]){
                count[i]--;
                count[i+1]--;
                count[i+2]--;
                tails[i+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};