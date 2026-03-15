class Solution {
public:
    bool isPowerOfFour(int n) {
        double k=n;
        while(k>=1){
            if(k==1)return 1;
            k/=4;
        }
        return 0;
    }
    
};