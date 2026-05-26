class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            bool small = false, capital = false;

            for(char c : word) {
                if(c == ch)
                    small = true;

                if(c == ch - 32)
                    capital = true;
            }

            if(small && capital)
                ans++;
        }

        return ans;
    }
};