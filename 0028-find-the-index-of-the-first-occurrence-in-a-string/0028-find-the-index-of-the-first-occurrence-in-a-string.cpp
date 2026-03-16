class Solution {
public:
    int strStr(string haystack, string needle) {
        int ansi=0;
        int j=0;
        int i;
        string ans="";
        for( i=0;i<haystack.length();i++){
            if (haystack[i] == needle[j]) {
                j++; 
                if (j == needle.length()) {
                    return i - needle.length() + 1; 
                }
            } else {
                i -= j; 
                j = 0; 
            }
        }
        return -1;
    }
};