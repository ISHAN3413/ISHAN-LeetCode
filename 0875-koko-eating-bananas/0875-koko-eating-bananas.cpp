class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int start = 1;
       sort(piles.begin(),piles.end());
       int end = piles[piles.size()-1];
       while(start<end){
        int mid = start + ((end-start)/2);
        int totalhour = 0;
        for(int i = 0;i<piles.size();i++){
            totalhour+=(piles[i]+mid-1)/mid;
        }
        if(totalhour<=h){
            end = mid;
        }
        else{
            start = mid+1;
        }
       } 
       return end;
    }
};