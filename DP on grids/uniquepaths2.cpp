class Solution {
public:
    int t[101][101];
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid){
        if(i>=m || j>=n)return 0;
        if(grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(t[i][j]!=-1)return t[i][j];
        return t[i][j] = solve(i+1, j, m, n, grid) + solve(i, j+1, m, n, grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){   
        memset(t, -1, sizeof(t));
        int n = obstacleGrid[0].size(), m = obstacleGrid.size();
        return solve(0, 0, m, n, obstacleGrid);
    }
};