class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = -1 , mx = INT_MIN;
        for(auto x : nums){
            if(x%2 == 0){
                m[x]++;
                if(m[x] > mx){
                    mx = m[x];
                    ans = x;
                }else if(m[x] == mx){
                    ans = min(ans , x);
                }
            }
        }
        return ans;
    }
};