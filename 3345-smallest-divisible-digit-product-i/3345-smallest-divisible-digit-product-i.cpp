class Solution {
public:
    int smallestNumber(int n, int t) {
        int a=n;
        int m=1;
        while(a<=INT_MAX){
        while(n!=0){
            m=m*(n%10);
            if(m%t==0){
                return a;
            }
            n=n/10;
        }
            m=1;
            a++;
            n=a;
        }
        return 0;
    }
};