class BalanceSegTree {
    int n;
    vector<int> segSum, segMin, segMax;

public:
    BalanceSegTree(int size) : n(size) {
        segSum.assign(4*n, 0);
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
    }

    void pull(int v) {
        int L = v << 1, R = L | 1;
        segSum[v] = segSum[L] + segSum[R];
        segMin[v] = min(segMin[L], segSum[L] + segMin[R]);
        segMax[v] = max(segMax[L], segSum[L] + segMax[R]);
    }

    void pointUpdate(int v, int l, int r, int idx, int val) {
        if (l == r) {
            segSum[v] = segMin[v] = segMax[v] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) pointUpdate(v<<1, l, m, idx, val);
        else pointUpdate(v<<1|1, m+1, r, idx, val);
        pull(v);
    }

    void update(int idx, int val) {
        pointUpdate(1, 0, n-1, idx, val);
    }

    bool canReach(int v, int prefix, int target) {
        int need = target - prefix;
        return segMin[v] <= need && need <= segMax[v];
    }

    int findRightmostZero(int v, int l, int r, int prefix) {
        if (!canReach(v, prefix, 0)) return -1;
        if (l == r) return l;

        int m = (l + r) >> 1;
        int leftSum = prefix + segSum[v<<1];

        int rightAns = findRightmostZero(v<<1|1, m+1, r, leftSum);
        if (rightAns != -1) return rightAns;

        return findRightmostZero(v<<1, l, m, prefix);
    }

    int findRightmostZero() {
        return findRightmostZero(1, 0, n-1, 0);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        BalanceSegTree st(n);

        unordered_map<int,int> firstPos;
        firstPos.reserve(n * 2);
        firstPos.max_load_factor(0.7f);

        int ans = 0;

        for (int l = n-1; l >= 0; --l) {
            int x = nums[l];

            if (firstPos.count(x))
                st.update(firstPos[x], 0);

            firstPos[x] = l;
            st.update(l, (x & 1) ? -1 : +1);

            int r = st.findRightmostZero();
            if (r >= l) ans = max(ans, r - l + 1);
        }
        return ans;
    }
};