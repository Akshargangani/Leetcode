class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n=nums.size();
        int best=0;
        int j=0;

        for(int i=0; i<n; i++) {
            while(j<n && (long long )nums[j] <=(long long)nums[i]*k){
                j++;
            }
            best =max(best,j-i);
        }
        return n-best;
    }
};