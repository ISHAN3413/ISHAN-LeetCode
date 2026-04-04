class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int marker = s.length();
        for(int i = s.length()-1 ; i>0 ;i--){
            if(s[i-1]>s[i]){
                s[i-1]--;
                marker = i;
            }
        }
        for(int i = marker ;i <s.length();i++){
            s[i] = '9';
        }
        return stoi(s);
    }
};