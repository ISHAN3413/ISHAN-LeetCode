class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(31 , 0);
        fib[0] = 1;
        fib[1] = 2;
        for(int i = 2;i<31;i++){
            fib[i] =fib[i-1] + fib[i-2];
        }
        int ans = 0;
        bool prev = 0;
        for(int i = 30 ; i>=0 ;i--){
            if((n &(1<<i))!=0){
                ans+=fib[i];
                if(prev)return ans;
                prev =1;
            }
            else{
                prev = 0;
            }
        }
        return ans+1;
    }
};