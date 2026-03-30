class SegmentTree{
public:
    int n;
    vector<int> tree;

    SegmentTree(vector<int>&arr){
        n = arr.size();
        tree.resize(n*4);
        build(arr , 0 , 0 , n-1);
    }

    void build(vector<int>&arr,int node , int l , int r){
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(arr , 2*node+1 , l , mid);
        build(arr , 2*node+2 , mid+1 , r);
        tree[node] = max(tree[2*node+1] , tree[2*node+2]);
    }

    int query(int node , int l ,int r , int target){
        if(tree[node] < target) return -1;

        if(l == r) return l;

        int mid = (l+r)/2;

        if(tree[2*node+1] >= target)
            return query(2*node+1 , l , mid , target);
        else
            return query(2*node+2 , mid+1 , r , target);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node] = 0; 
            return;
        }
        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2*node + 1, l, mid, idx);
        else
            update(2*node + 2, mid + 1, r, idx);

        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree seg(baskets);
        int unplaced = 0;
        for(int i =0;i<fruits.size();i++){
            int idx = seg.query(0,0,n-1,fruits[i]);
            if(idx == -1)unplaced++;
            else seg.update(0, 0, n - 1, idx);
        }
        return unplaced;
    }
};