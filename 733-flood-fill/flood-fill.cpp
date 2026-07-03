class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] == color)
            return image;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        int oldColor = image[sr][sc];
        q.push({sr, sc});

        image[sr][sc] = color;

        while (!q.empty()) {
            pair<int, int> front = q.front();
            int x = front.first;
            int y = front.second;
            q.pop();

            for (auto it : dir) {
                int nx = x + it.first;
                int ny = y + it.second;

                if (nx >= 0 && ny >= 0 && nx < image.size() &&
                    ny < image[0].size() && image[nx][ny] == oldColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};