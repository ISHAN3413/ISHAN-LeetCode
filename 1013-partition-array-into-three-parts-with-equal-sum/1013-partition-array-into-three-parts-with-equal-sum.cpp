class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        int a = arr[arr.size()-1];
        if(a%3!=0)return false;
        int f = a/3;
        int s = 2*f;
        bool fi = false;
        bool si = false;
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i]==f && !fi)fi=true;
            else if(arr[i]==s && fi)return true;
        }
        return false;
    }
};