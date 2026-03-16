class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> a(2*n , 0);
        vector<int> b(2*n , 0);
        for(int i =0 ; i<2*n;i++){
            a[i] = nums[i%n];
        }
        stack<int> s;
        for(int i=a.size()-1 ; i>=0 ; i--){
            while(!s.empty() && s.top()<=a[i]){
                s.pop();
            }
            if(s.empty()){
                b[i] = -1;
            }
            else{
                b[i] = s.top();
            }
            
            s.push(a[i]);
        }
        for(int j=0;j<n;j++){
            ans[j] = b[j];
        }
        return ans;
    }
};