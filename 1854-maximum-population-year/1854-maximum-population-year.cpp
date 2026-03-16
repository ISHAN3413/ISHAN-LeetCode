class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        std::vector<int> arr(101, 0);
        for(int i=0;i<logs.size();i++){
            for(int j=logs[i][0]-1950;j<logs[i][1]-1950;j++){
                arr[j]++;
            }
        }
        int ans = 0;
        int a=arr[0];
         for(int k=0;k<101;k++){
            if(a<arr[k]){
                ans=k;
                a=arr[k];
            }
         }
         return 1950+ans;
    }
};