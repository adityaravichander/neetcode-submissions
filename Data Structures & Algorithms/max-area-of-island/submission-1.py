class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        rows = len(grid)
        cols = len(grid[0])
        maxArea = 0

        def dfs(grid, r, c) -> int:
            if r>=0 and r<rows and c>=0 and c<cols and grid[r][c] == 1:
                grid[r][c] = 0
                return 1 + dfs(grid,r-1,c) + dfs(grid, r+1, c) + dfs(grid, r, c-1) + dfs(grid, r, c+1)
            else: 
                return 0
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, dfs(grid, i , j))

        return maxArea