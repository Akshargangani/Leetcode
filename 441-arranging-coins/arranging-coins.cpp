class Solution {
public:
    int arrangeCoins(int n) {
        long l=1, r=n;
        while(l<=r) {
            long m=(l+r)/2;
            long s=m*(m+1)/2;
            if(s==n) return m;
            if(s<n) l=m+1;
            else r=m-1;
        }
        return r;
    }
};