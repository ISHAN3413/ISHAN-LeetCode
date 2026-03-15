class Solution {
public:
    bool isPowerOfThree(int n) {
        double k=n;
        while(k>=1){
            if(k==1)return 1;
            k/=3;
        }
        return 0;
    }
};