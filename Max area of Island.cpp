class Solution {
public:

    int helperDFS(vector<vector<int> >& grid, vector<vector<bool> >& visited, int x, int y ) {

        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y])
            return 0;

        visited[x][y] = true ;

        return 1 + helperDFS(grid, visited, x - 1, y) + helperDFS(grid, visited, x + 1, y) + helperDFS(grid, visited, x, y - 1) + helperDFS(grid, visited, x, y + 1) ;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));

        int maxArea = 0;

        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (!visited[i][j])
                    maxArea = max(maxArea, helperDFS(grid, visited, i, j));
            }
        }

        return maxArea;

    }
};

// Accepted 16 ms , 23.6 MB
