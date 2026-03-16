class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(),arr.end());
        int a = arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
           int j = i+1;
           if((arr[j]-arr[i])!=a)return false;
        }
        return true;
    }
};