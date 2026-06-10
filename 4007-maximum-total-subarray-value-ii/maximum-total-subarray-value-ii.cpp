class Solution {
public:
    using ll = long long;

    struct Node {
        ll val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    int queryMax(int l, int r) {
        int j = lg[r - l + 1];
        return max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
    }

    int queryMin(int l, int r) {
        int j = lg[r - l + 1];
        return min(stMin[j][l], stMin[j][r - (1 << j) + 1]);
    }

    ll getValue(int l, int r) {
        return 1LL * queryMax(l, r) - queryMin(l, r);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        // log table
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(stMax[j - 1][i],
                                  stMax[j - 1][i + (1 << (j - 1))]);

                stMin[j][i] = min(stMin[j - 1][i],
                                  stMin[j - 1][i + (1 << (j - 1))]);
            }
        }

        priority_queue<Node> pq;

        // Start with every subarray ending at n-1
        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        while (k-- && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            // move r left
            if (cur.r - 1 >= cur.l) {
                pq.push({
                    getValue(cur.l, cur.r - 1),
                    cur.l,
                    cur.r - 1
                });
            }
        }

        return ans;
    }
};