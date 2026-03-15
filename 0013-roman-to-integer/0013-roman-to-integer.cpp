class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char,int> m;
        long long int k=0;
        int i=0;
         m['I']=1;
         m['V']=5;
         m['X']=10;
         m['L']=50;
         m['C']=100;
         m['D']=500;
         m['M']=1000;
        for(int i=0;i<s.length();i++){
           if((i+1<s.length())&&(m[s[i]]<m[s[i+1]])){
            k=k-(m[s[i]]);
            } 
          else k=k+(m[s[i]]);
        }
            return k;
    }
};