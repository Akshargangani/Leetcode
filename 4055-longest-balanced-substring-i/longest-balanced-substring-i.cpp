class Solution {
public:
    
    bool isBalanced(unordered_map<char, int>& mp, int value) {
        for (auto it : mp) {
            if (it.second != value) {
                return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                if (isBalanced(mp, mp[s[j]])) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
