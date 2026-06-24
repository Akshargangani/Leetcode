class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiplyMatVec(const Matrix& A,
                                     const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;

            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int sz = 2 * m;

        vector<long long> state(sz, 0);

        // Length = 2 initialization
        for (int x = 0; x < m; x++) {
            state[x] = x;                 // up[x]
            state[m + x] = (m - 1 - x);  // down[x]
        }

        if (n == 2) {
            long long ans = 0;
            for (long long x : state) ans = (ans + x) % MOD;
            return (int)ans;
        }

        Matrix T(sz, vector<long long>(sz, 0));

        // up_new[w] = sum down[v] where v < w
        for (int w = 0; w < m; w++) {
            for (int v = 0; v < w; v++) {
                T[w][m + v] = 1;
            }
        }

        // down_new[w] = sum up[v] where v > w
        for (int w = 0; w < m; w++) {
            for (int v = w + 1; v < m; v++) {
                T[m + w][v] = 1;
            }
        }

        long long power = n - 2;

        while (power > 0) {
            if (power & 1) {
                state = multiplyMatVec(T, state);
            }

            T = multiply(T, T);
            power >>= 1;
        }

        long long ans = 0;

        for (long long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};