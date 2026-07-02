class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        priority_queue<vector<int>> pq;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        pq.push({startHealth, 0, 0});
        best[0][0] = startHealth;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int hp = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (x == m - 1 && y == n - 1)
                return true;

            if (hp < best[x][y])
                continue;

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newHealth = hp - grid[nx][ny];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nx][ny]) {

                    best[nx][ny] = newHealth;
                    pq.push({newHealth, nx, ny});
                }
            }
        }

        return false;
    }
};