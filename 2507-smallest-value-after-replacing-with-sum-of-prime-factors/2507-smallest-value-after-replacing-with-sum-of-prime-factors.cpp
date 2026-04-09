class Solution {
public:
    int smallestValue(int n) {
        int a = n;
        int b;
        while(true){
           b = minSteps(a);
            if(b==a)break;
            a=b;
        }
        return a;
    }
    int minSteps(int n) {
        int d = 2;
        int ans = 0;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};