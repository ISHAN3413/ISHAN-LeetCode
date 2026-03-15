class Solution {
public:
    char findTheDifference(string s, string t) {
        int k=0;
    for(char c:t){
        k+=c;
    }
    for(char c:s){
        k-=c;
    }    
    return k;
    }
};