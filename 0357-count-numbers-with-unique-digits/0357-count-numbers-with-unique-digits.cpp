class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        // if(n==1)return 9+countNumbersWithUniqueDigits(n-1);
        // if(n==2)return 9*9 + countNumbersWithUniqueDigits(n-1);
        int t = 9;
        int num = 9;
        for(int i = 0 ; i<n-1 ; i++){
            num*=t;
            t--;
        }
        return num+countNumbersWithUniqueDigits(n-1);
    }
};