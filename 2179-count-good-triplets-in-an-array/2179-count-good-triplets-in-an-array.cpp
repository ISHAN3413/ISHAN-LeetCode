class Solution {
public:
    vector<int> seg;
    void update(int ind, int low, int high, int pos) {
        if (low == high) {
            seg[ind] = 1;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)update(2 * ind + 1, low, mid, pos);
        else update(2 * ind + 2, mid + 1, high, pos);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        if (r < low || high < l) return 0;
        if (l <= low && high <= r) return seg[ind];
        int mid = (low + high) / 2;
        return query(2 * ind + 1, low, mid, l, r) +query(2 * ind + 2, mid + 1, high, l, r);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        vector<int> m(n) ; 
        vector<int> pos(n);
        for(int i = 0;i<nums1.size();i++){
            pos[nums2[i]]=i;
        }
        for(int i = 0;i<nums2.size();i++){
            m[i]=pos[nums1[i]];
        }
        seg.assign(4*n , 0);
        long long ans = 0;
         for(int i = 0;i<n;i++){
            int ls = 0;
            ls = query(0,0,n-1,0,m[i]-1);
            int rs = (n-1-m[i])-(i-ls);

        //     int ls = 0;
        //     for(int j =0;j<i;j++){
        //        if(m[j]<m[i])ls++;
        //     }
        //     int rs = 0;
        //     for(int k = i+1;k<n;k++){
        //        if(m[i]<m[k])rs++;
        //     }
             ans+=1LL*ls*rs;
             update(0,0,n-1,m[i]);
         }
        return ans;
    }
};