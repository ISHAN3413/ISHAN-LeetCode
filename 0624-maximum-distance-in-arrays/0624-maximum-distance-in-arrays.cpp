class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // vector<vector<int>> mini , maxi ;
        // sort(arrays.begin() , arrays.end(), [](auto &a , auto &b){
        //     return a[0]<b[0];
        // });
        // mini = arrays;
        // sort(arrays.begin() , arrays.end(), [](auto &a , auto &b){
        //     int n = a.size()-1;
        //     int m = b.size()-1;
        //     return a[n]>b[m];
        // });
        // maxi = arrays;

        // if(mini[0] == maxi[0]){
        //     int a = abs(mini[0][0] - maxi[1][maxi[1].size()-1]);
        //     int b = abs(mini[1][0] - maxi[0][maxi[0].size()-1]);
        //     return max(a,b);
        // }
        // else{
        //     return abs(mini[0][0] - maxi[0][maxi[0].size()-1]);
        // }

        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int ans = 0;
        for(int i =1 ; i< arrays.size();i++){
            ans = max(ans , abs(arrays[i].back() - mini));
            ans = max(ans , abs(arrays[i][0] - maxi));
             mini = min(mini , arrays[i][0]);
             maxi = max(maxi , arrays[i].back());
        }
        return ans;
    }
};