class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     vector<int> main;
     std::unordered_map<int,int> m;
     stack<int> a;
     int j=1;
     for(int i = nums2.size()-1 ; i>=0 ; i--){
        while(a.size() && a.top()<=nums2[i] ){
           a.pop();
        }
        if(a.empty()){
            m[nums2[i]] = -1;
        }
        else{
            m[nums2[i]] = a.top();
        }
        a.push(nums2[i]);
     }
        for(int nums:nums1){
            main.push_back(m[nums]);
        }

     return main;
    }
};