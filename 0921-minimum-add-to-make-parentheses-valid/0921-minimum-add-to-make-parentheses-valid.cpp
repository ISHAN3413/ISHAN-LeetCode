class Solution {
public:
    int minAddToMakeValid(string s) {
        int i = 0;
       int k = 0,j=0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                k++;
            else{
                if(k>0){
                    k--;
                }
                else j++;
            }
                
        }
        return {k+j};
    }
};