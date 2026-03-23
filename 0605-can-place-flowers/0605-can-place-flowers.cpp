class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans;
        for(int i=0;i<f.size();i++){
            if(f[i]==0){
            int left = (i==0)?0:f[i-1];
            int right = (i==f.size()-1)?0:f[i+1];
            if(left ==0 && right==0){
                f[i]=1;
                ans++;
                i++;
            }}
        }
        return (ans>=n);
    }
};