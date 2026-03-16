class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans1="";
        string ans2="";
        bool a=0;
        for(int i=0;i<word.length();i++){
            if(!a){
            ans1+=word[i];
            if(word[i]==ch){
               a=1;
            }}
            else ans2+=word[i];
        }
        if(!a)return word;
        reverse(ans1.begin(),ans1.end());
        return ans1+ans2;
    }
};