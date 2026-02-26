class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0)return 1;
        vector<int> h(n+1 , 0);
        for(int i = 0;i<trust.size();i++){
            h[trust[i][0]] = -1;
            if(h[trust[i][1]]!=-1)h[trust[i][1]]++;
        }
        for(int i = 0 ; i<=n ;i++){
            if(h[i]==n-1)return i;
        }
        return -1;
    }
};