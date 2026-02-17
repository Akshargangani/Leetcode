class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int num = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (num <= prev)
                    return false;
                prev = num;
            }
        }

        return true;
    }
};
