class Solution {
public:
    string convertToBase7(int n) {
        if(n==0) return "0";
        bool neg=n<0; n=abs(n);
        string s="";
        while(n){
            s=char(n%7+'0')+s;
            n/=7;
        }
        return neg?("-"+s):s;
    }
};
