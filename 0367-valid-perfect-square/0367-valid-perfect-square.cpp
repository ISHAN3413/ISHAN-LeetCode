class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2)return 1;
        int right=num/2;
        for(int i=1;i<=right;i++){
            long long square=(long long )i*i;
            if(square==num){
                return 1;
            }
        }
        return 0;
    }
};