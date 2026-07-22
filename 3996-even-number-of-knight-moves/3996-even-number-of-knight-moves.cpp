class Solution {
    #define us unordered_set<int>
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        us s;
        return f(start,target,0,s);
    }
    bool f(vector<int>& start ,vector<int>&target, int moves ,us &s){
        if(start[0]<0 || start[1]<0 || start[0]>=8 || start[1]>=8)return false;
        int key = start[0]*8 + start[1];
        if(s.find(key)!=s.end())return false;
        s.insert(key);
        if(start==target){
            return (moves%2 ==0 );
        }

       int a[8] = {-1,-2,-2,-1,1,2,2,1};
       int b[8] = {-2,-1,1,2,-2,-1,1,2};

       for(int i = 0;i<8;i++){
        vector<int>sta = {start[0]+a[i],start[1]+b[i]};
        if(f(sta,target,moves+1,s))return true;
       }
       return false;






    }
};