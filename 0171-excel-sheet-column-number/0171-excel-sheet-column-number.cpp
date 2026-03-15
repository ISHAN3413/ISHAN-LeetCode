class Solution {
public:
    int titleToNumber(string c) {
        int k=c[0]-'A'+1;
        for(int i=1;i<c.length();i++){
            k=k*26+(c[i]-'A'+1);
        }
        return k;
    }
};