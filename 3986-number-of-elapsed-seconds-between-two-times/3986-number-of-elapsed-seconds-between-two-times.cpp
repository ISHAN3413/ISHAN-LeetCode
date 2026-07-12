class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int ans = 0;
        
        int hmul = 3600;
        int mmul = 60;

        int hos = (st[0]-'0')*10 + (st[1]-'0');
        int mis = (st[3]-'0')*10 + (st[4]-'0');
        int ses = (st[6]-'0')*10 + (st[7]-'0');

        int hoe = (et[0]-'0')*10 + (et[1]-'0');
        int mie = (et[3]-'0')*10 + (et[4]-'0');
        int see = (et[6]-'0')*10 + (et[7]-'0');

        int start = hos*3600 + mis*60 + ses;
        int end = hoe*3600 + mie*60 + see;

        if(end<start){
            end+=24*3600;
        }
    return end-start;
        
        
    }
};