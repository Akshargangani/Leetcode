class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long result = 0;
        int mod = 1e9 + 7;
        int length = 0;
        
        for (int i = 1; i <= n; i++) {
            
            
            if ((i & (i - 1)) == 0) {
                length++;
            }
            
            
            result = ((result << length) + i) % mod;
        }
        
        return (int)result;
    }
};