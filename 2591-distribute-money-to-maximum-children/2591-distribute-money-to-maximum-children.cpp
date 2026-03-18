class Solution {
public:
    int distMoney(int m, int c) {
        if(m<c)return -1;
        int a = m-c;
        int b=a/7;
        if(b<c){
            int rem = a%7;
            if(rem==3 && (c-b==1))return b-1;
            return b;
        }
        else if(b==c){
           if(a%7==0)return b;
           return b-1;
        }
        else{
            return c-1;
        }

    }
};