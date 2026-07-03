class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int min = 0;
        int total = 0;
        int count = 0;
        queue<pair<int, int>> rotten;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0)
                 total++;
                if(grid[i][j] == 2)
                rotten.push({i,j}); 
            }
        }
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        while(!rotten.empty()){
            int k = rotten.size();
            count += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for(int i=0; i<4; i++){
                    int nrow = x + dx[i];
                    int ncol = y + dy[i];   
                    if(nrow<0 || ncol<0 || nrow>=m || ncol>=n || grid[nrow][ncol] != 1)  
                    continue;
                    grid[nrow][ncol] = 2;
                    rotten.push({nrow,ncol});
                }
            }
            if(!rotten.empty()){
                min++;
            }
        }
        return total == count ? min: -1;
    }
};