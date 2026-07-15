class Solution {
public:
vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        // Union by Rank
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) != find(v)) {
                unite(u, v);
                components--;
            }
        }

        return components - 1;
    }
};