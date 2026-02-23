class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return 0;
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=1;
        }
        int prev=0;
        bool check=false;
        int ans=0;
        for(auto [key,value]:mpp){
            if(check){
                ans=max(ans,key-prev);
            }
            prev=key;
            check=true;
        }
        
        return ans;
    }
};