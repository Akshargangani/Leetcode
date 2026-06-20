class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> sums;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long cur = root->val;
        cur += dfs(root->left);
        cur += dfs(root->right);

        sums.push_back(cur);
        return cur;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans = 0;

        for (long long s : sums) {
            ans = max(ans, s * (total - s));
        }

        return ans % MOD;
    }
};