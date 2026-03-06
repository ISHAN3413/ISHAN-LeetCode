class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag1,flag2=false;
        for(int i =0;i<s.length();i++){
            if(flag1 && flag2 &&(s[i]=='1')){
                return false;
            }
            if(s[i]=='1'){
                flag1 = true;
            }
            if(s[i]=='0' && flag1){
                flag2 = true;
            }
        }
        return true;
    }
};