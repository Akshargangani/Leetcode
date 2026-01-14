class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,a=0;
        for(int x:nums){
            if(c==0) a=x;
            c+=(x==a)?1:-1;
        }
        return a;
    }
};

