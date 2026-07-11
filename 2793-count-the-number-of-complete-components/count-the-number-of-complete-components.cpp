class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited,
             vector<int>& component) {

        visited[node] = true;
        component.push_back(node);

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next, graph, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int answer = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i]) continue;

            vector<int> component;

            dfs(i, graph, visited, component);

            int nodes = component.size();
            int edgeCount = 0;

            for (int node : component) {
                edgeCount += graph[node].size();
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2) {
                answer++;
            }
        }

        return answer;
    }
};