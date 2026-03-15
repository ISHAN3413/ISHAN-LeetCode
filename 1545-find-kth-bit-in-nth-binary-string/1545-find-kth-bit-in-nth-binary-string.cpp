class Solution {
public:
    char findKthBit(int n, int k) {
        std::unordered_map<int,std::string> m;
       string s="";
        m[1]="0";
        for(int i=2;i<=n;i++){
            m[i]=m[i-1]+"1"+invertnreverse(m[i-1]); 
        }
       
       return m[n][k-1];
    }
    private:
    std::string invertnreverse(const std::string& s){
        std::string inverted="";
        for (char c : s) {
            inverted += (c == '0') ? '1' : '0';
        }
        std::reverse(inverted.begin(),inverted.end());
        return inverted;
        
    }
};