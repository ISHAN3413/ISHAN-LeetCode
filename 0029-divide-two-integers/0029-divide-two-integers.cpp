class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if(divisor==1)return dividend;
        if(divisor==-1){
            if(dividend==INT_MIN) return INT_MAX;
            return -dividend;
        }
        bool neg=(dividend<0)!=(divisor<0);
        long long a= abs(static_cast <long long>(dividend));
        long long b= abs(static_cast <long long>(divisor));
        long long int i=0;
        while(a>=b){
            a=a-b;
            i++;
        }
        return neg?-i:i;
    }
};