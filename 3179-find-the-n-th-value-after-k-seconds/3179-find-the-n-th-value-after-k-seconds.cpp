class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod=pow(10,9)+7;
        std::vector<long long> a(n,1);
        for(int i=1;i<=k;i++){
            for(long long j=1;j<n;j++){
            a[j]=(a[j-1]+a[j])%mod;
            }
        }
        return a[n-1];
    }
};