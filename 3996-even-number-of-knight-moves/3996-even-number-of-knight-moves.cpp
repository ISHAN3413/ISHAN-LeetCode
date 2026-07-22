class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int si = start[0]+start[1];
        int ti = target[0]+target[1];
        if(si%2 == ti%2)return true;
        return false;
    }
};