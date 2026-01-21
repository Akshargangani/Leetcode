class Solution {
public:
    int findNumbers(vector<int>& nums) {
         int cnt=0;
          for(int x:nums){
            int d=0;
            while(x){ d++; x/=10; }
            if(d%2==0) cnt++;
        }
        return cnt;
    }
};