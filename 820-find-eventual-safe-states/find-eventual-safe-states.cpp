class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& pathVis, vector<int>& check) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : graph[node]) {

            if (!vis[it]) {
                if (dfs(it, graph, vis, pathVis, check))
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (check[i])
                ans.push_back(i);
        }

        return ans;
    }
};