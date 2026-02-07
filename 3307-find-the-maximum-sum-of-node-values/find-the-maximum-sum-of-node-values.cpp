class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int cnt = 0;
        long long minLoss = LLONG_MAX;

        for (int x : nums) {
            long long y = x ^ k;
            if (y > x) {
                sum += y;
                cnt++;
                minLoss = min(minLoss, y - x);
            } else {
                sum += x;
                minLoss = min(minLoss, x - y);
            }
        }

        if (cnt % 2 == 1) sum -= minLoss;
        return sum;
    }
};
