class Solution {
public:
    int reverse(int val) {
        int newnum = 0;
        while (val != 0) {
            int x = val % 10;
            val /= 10;
            newnum = newnum * 10 + x;
        }
        return newnum;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mindist = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (mp.find(nums[i]) != mp.end()) {
                mindist = min(mindist, i - mp[nums[i]]);
            }
            int rev = reverse(nums[i]);
            mp[rev] = i;
        }
        return mindist == INT_MAX ? -1 : mindist;
    }
};