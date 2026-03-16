class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int a[1001] = {0};
        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                if (i != j) {
                    for (int k = 0; k < digits.size(); k++) {
                        if (k != j && digits[i] != 0 &&digits[k]%2==0 && k!=i) {
                            a[digits[i] * 100 + digits[j] * 10 + digits[k]]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 1000; i++){
            if(a[i]!=0)ans++;
        }
        return ans;
    }
};