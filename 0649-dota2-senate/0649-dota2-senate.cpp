class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> r;
        queue<int> d;
        for(int i = 0;i<senate.length();i++){
            if(senate[i]=='R')r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int rf = r.front();
            int df = d.front();
            r.pop();
            d.pop();
            if(rf<df){
                r.push(rf+n);
            }
            else{
                d.push(df+n);
            }
        }
        return r.empty()?"Dire":"Radiant";
    }
};