class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rb = 0;

        for(int val:data){
            if(rb == 0){
                int count = 0;
                for(int i = 7 ; i>=0 ;i--){
                    if((val>>i)&1)count++;
                    else break;
                }
                if(count ==0 )continue;
                if(count == 1 ||count>4)return false;
                rb = count-1;
            }
            else{
                if(!((val>>7)&1))return false;
                if((val>>6)&1)return false;
                rb--;
            }
        }
        return rb == 0;
    }
};