class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        return f1(matchsticks);
    }
    bool f1(vector<int> &m){
        int target = 0;
        for(int i:m){
            target+=i;
        }
        if(target%4 !=0 )return false;
        target/=4;
        sort(m.begin(),m.end(),[](int a , int b){
            return a>b;
        });
        if(m[0]>target)return false;
        vector<int> s(4,0);
        return f(m ,s ,0,target);
    }
    bool f(vector<int> &m , vector<int>&s , int i ,  int target){
        if(i == m.size()){
            return ((s[0] == target)&&(s[1] == target)&&(s[2] == target)&&(s[3] == target));
        }

        for(int j = 0;j<4;j++){
            if(s[j]+m[i]<=target){
                s[j]+=m[i];
              if(f(m,s,i+1,target))return true;
            s[j]-=m[i];  
            }
            if(s[j] == 0)break;
        }
        return false;
    }
};