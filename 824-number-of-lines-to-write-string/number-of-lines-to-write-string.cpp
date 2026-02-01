class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        int lines = 1, cur = 0;
        for(char c : s){
            int x = w[c-'a'];
            if(cur + x > 100) lines++, cur = x;
            else cur += x;
        }
        return {lines, cur};
    }
};
