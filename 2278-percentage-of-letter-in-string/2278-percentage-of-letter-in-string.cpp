class Solution {
public:
    int percentageLetter(string s, char letter) {
        int a = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==letter)a++;
        }
        return a*100/s.length();
    }
};