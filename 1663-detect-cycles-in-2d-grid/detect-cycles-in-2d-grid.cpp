class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py, char ch) {
        visited[x][y] = 1;
        
        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != ch) continue;
            
            if (!visited[nx][ny]) {
                if (dfs(grid, nx, ny, x, y, ch)) return true;
            } 
            else if (nx != px || ny != py) {
                return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};