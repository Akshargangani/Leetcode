class Solution {
public:
    inline int convert(int x){
        int y=0;
        for(int x0=x; x0>0; x0/=10){
            y+=x0%10;
        }
        return y;
    }
    int minElement(vector<int>& nums) {
        int Xmin=INT_MAX;
        for(int x: nums)
            Xmin=min(Xmin, convert(x));
        return Xmin;
    }
};