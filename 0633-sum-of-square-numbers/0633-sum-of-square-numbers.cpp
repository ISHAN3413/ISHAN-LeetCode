class Solution {
public:
    bool judgeSquareSum(int c) {
            for(long long i=0;i*i<=c;i++){            
           long long j=sqrt(c-i*i);               
            if(i*i+j*j==c)return 1;
             }
        
        return 0;
    }
};