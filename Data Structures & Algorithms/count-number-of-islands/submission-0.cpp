class Solution {
public:

    int numIslands(vector<vector<char>>& grid) 
    {
        
        if(grid.empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        //traverse, check if it's 1

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    // grid[i][j] = '0';
                    // cout << grid[i][j];
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;

    }

    void dfs(int i, int j, vector<vector<char>>& g)
    {
        int r = g.size();
        int c = g[0].size();

        bool legit;

        if(i>=0 && i<r && j>=0 && j<c)
            legit = true;
        else
            legit = false;

        if(legit == true && g[i][j] == '1')
        {
            g[i][j] = '0';
            dfs(i,j-1,g);
            dfs(i,j+1,g);
            dfs(i-1,j,g);
            dfs(i+1,j,g);
        }
        else
            return;

    }

};
