class Solution {
public:
    int minElement(vector<int>& nums) {
        int k,s,m=1000000;
        for(int i=0;i<nums.size();i++){
            k=nums[i];
            s=0;
            while(k!=0){
                s=s+(k%10);
                k=k/10;
            }
            m=min(m,s);
        }
        return{m};

    }
};