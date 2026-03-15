class Solution {
public:
    bool isPalindrome(string s) {
         vector<char> a;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
            if('A'<=s[i]&&'Z'>=s[i])s[i]=s[i]+'a'-'A';
                a.push_back(s[i]);
            }
        }
        if(ispalindrome(a))return 1;
        return 0;
    }
    private:
    bool ispalindrome(vector<char> &a){
        std::vector<char> reversed=a;
        reverse(reversed.begin(),reversed.end());
        if(a==reversed)return 1;
        return 0;
    }
};