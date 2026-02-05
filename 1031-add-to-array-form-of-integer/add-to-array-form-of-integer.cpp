class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int i=a.size()-1;
        while(i>=0 || k){
            if(i>=0) k+=a[i];
            if(i>=0) a[i]=k%10;
            else a.insert(a.begin(),k%10);
            k/=10; i--;
        }
        return a;
    }
};
