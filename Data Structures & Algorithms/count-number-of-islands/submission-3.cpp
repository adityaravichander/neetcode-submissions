class Solution {
    int directions[4][2] = {{1,0}, {-1,0},
                            {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty())
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    // dfs(i,j,grid);
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
        
    }

    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        grid[i][j] = '0';  //visited
        q.push({i,j});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + directions[d][0];
                int nc = c + directions[d][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1')
                    {
                        q.push({nr,nc});
                        grid[nr][nc] = '0';
                    }
            }
        }

    }


    // void dfs(int i, int j, vector<vector<char>>&g)
    // {
    //     int r = g.size();
    //     int c = g[0].size();

    //     bool legit;
        
    //     if(i>=0 && i<r && j>=0 && j<c)
    //         legit = true;
    //     else
    //         legit = false;

    //     if(legit == true && g[i][j] == '1')
    //         {
    //             g[i][j] = '0';
    //             dfs(i, j-1, g);
    //             dfs(i, j+1, g);
    //             dfs(i-1, j, g);
    //             dfs(i+1, j, g);
    //         }
    //     else
    //         return;
    // }
};
