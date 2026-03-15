class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
       std::vector<int> a;
       while(n!=0){
        a.push_back(n%2);
        n=n/2;
       }
        int b=0;
       for(int i=0;i<a.size();i++){
        b+=(1-a[i])*(1<<i);
       }
       return b;
    }
};