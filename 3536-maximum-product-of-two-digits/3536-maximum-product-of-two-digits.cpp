class Solution {
public:
    int maxProduct(int n) {
        string a = to_string(n);
        sort(a.begin(),a.end(),[](char a , char b){
            return a>b;
        });
        return (a[0]-'0')*(a[1]-'0');
    }
};