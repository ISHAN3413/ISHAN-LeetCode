class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<long long> diff(n+1,0);
        int i=1;
        for(const auto& shift:shifts){
            diff[0]+=shift;
            if (i < n)diff[i]-=shift;
            i++;
        }
        long long cshift=0;
        for(int i=0;i<n;i++){
            cshift+=diff[i];
            s[i] = 'a' + (s[i] - 'a' + ((cshift % 26 + 26) % 26)) % 26;
        }
        return s;
    }
};