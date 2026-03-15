class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<=s.size();i++){
            if(s==goal)return 1;
            shift(s);            
        }
        return 0;
    }
    private:
    void shift(string &s){
        for(int i=1;i<s.size();i++){
            swap(s[i],s[i-1]);
        }
    }
};