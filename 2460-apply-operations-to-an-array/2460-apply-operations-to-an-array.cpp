class Solution {
public:
    vector<int> applyOperations(vector<int>& a) {
        vector<int> b;
        int k=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]!=a[i+1])continue;
            a[i]=2*a[i];
            a[i+1]=0;
        }
       for(int i=0;i<a.size();i++){
        if(a[i]!=0)b.push_back(a[i]);
       }
      k=b.size();
       for(int i=0;i<a.size()-k;i++){
       b.push_back(0);
       }
       return b;
    }
};