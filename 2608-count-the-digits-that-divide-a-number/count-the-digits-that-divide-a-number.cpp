class Solution {
public:
    int countDigits(int num) {
        int number = num;
        int x = 0;
        int val;
        while (num > 0) {
            val = num % 10;
            num = num / 10;
            if (number % val == 0) {
                x = x + 1;
            }
        }
        return x;
    }    
};