class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= (m * n);
        vector<vector<int>>ans(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int newI = (i * n + j + k)%(m*n);

                int newR = newI / n;
                int newC = newI % n;
                ans[newR][newC] = grid[i][j];
            }
        }
        return ans;
    }
};