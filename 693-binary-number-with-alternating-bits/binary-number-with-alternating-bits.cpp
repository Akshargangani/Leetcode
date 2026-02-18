class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;
        n /= 2;
        while (n) {
            int curr = n % 2;
            if (curr == prev) return false;
            prev = curr;
            n /= 2;
        }
        return true;
    }
};