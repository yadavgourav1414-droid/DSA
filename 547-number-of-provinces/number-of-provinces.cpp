class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, 
    vector<int>&visited) {

        visited[node] = 1;
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[node][j]==1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};