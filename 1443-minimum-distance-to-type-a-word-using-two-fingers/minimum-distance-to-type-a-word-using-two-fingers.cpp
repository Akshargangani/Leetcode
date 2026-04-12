class Solution {
public:
    void getPositions(unordered_map<int,pair<int,int>>& mpp){
        char c = 'A';
        for(int i=0; i<5; i++){
            for(int j=0; j<6; j++){
                if(c <= 'Z') {
                    mpp[c-'A'] = {i, j};
                    c++;
                }
            }
        }
    }

    int getDist(pair<int,int> a, pair<int,int> b){
        return abs(a.first-b.first) + abs(a.second-b.second);
    }

    int mnDist(int i, int j, int k, string& word, 
               unordered_map<int,pair<int,int>>& mpp, 
               vector<vector<vector<int>>>& dp){

        if(k >= word.size()) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int curr = word[k] - 'A';

        int t1, t2;

        // Use finger 1
        if(i == 26)
            t1 = mnDist(curr, j, k+1, word, mpp, dp);
        else
            t1 = getDist(mpp[i], mpp[curr]) +
                 mnDist(curr, j, k+1, word, mpp, dp);

        // Use finger 2
        if(j == 26)
            t2 = mnDist(i, curr, k+1, word, mpp, dp);
        else
            t2 = getDist(mpp[j], mpp[curr]) +
                 mnDist(i, curr, k+1, word, mpp, dp);

        return dp[i][j][k] = min(t1, t2);
    }

    int minimumDistance(string word) {
        unordered_map<int,pair<int,int>> mpp;
        getPositions(mpp);

        vector<vector<vector<int>>> dp(
            27, vector<vector<int>>(27, vector<int>(301, -1))
        );

        return mnDist(26, 26, 0, word, mpp, dp);
    }
};