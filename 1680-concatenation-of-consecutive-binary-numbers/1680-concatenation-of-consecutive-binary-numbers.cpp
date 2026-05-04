class Solution {
public:
    int concatenatedBinary(int n) {
        long long rem = 1e9 + 7;
        long long ans = 0;
        long long pot = 1;
        int nums = n;
        while(nums!=0){
            int a = nums;
            while(a!=0){
                if(a&1){
                   ans = (ans+pot)%rem;
                }
                pot = (pot*2 )% rem;
                a>>=1;
            }
            nums--;
        }
        return (int)ans;
    }
};