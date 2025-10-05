class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int ans = INT_MIN;

        for(int  n: nums){
            sum = max(n, sum+n);
            ans = max(ans,sum);
        }
        return ans;
    }
};