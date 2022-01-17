class Solution {
public:
    int dp[101][101];
    vector<vector<int>> g;
    int n, m;
    int solveIt(int x, int y) {
        if(x == n - 1 && y == m - 1)
            return 1;
         
        if(x >= n || y >= m)
            return 0;
        
        if(g[x][y] == 1)
            return 0;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
            
        int p = solveIt(x + 1, y);
        int q = solveIt(x, y + 1);
        
        return dp[x][y] = p + q;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        g = obstacleGrid;
        n = g.size();
        m = g[0].size();
        memset(dp, -1, sizeof dp);
        if (g[n - 1][m - 1] == 1) return 0;
        return solveIt(0,0);
        
    }
};