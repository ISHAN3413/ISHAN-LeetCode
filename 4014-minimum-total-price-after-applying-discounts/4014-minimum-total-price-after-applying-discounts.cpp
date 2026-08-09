class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin() , prices.end(),[](int a , int b){
            return a>b;
        });
         sort(discounts.begin() , discounts.end(),[](int a , int b){
            return a>b;
        });
        double ans = 0;
        int i = 0,j=0;
        while(i<prices.size()){
            if(j<discounts.size()){
                ans+=(prices[i]*(100-discounts[j]))/100.00;
                j++;
            }
            else{
                ans+=prices[i];
            }
            i++;
        }
        return ans;
    }
};