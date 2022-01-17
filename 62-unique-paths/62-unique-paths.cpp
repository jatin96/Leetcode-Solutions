class Solution {
public:
    int dp[101][101];
    int solveIt(int x, int y, int n ,int m) {
        if(x == n - 1 && y == m - 1)
            return 1;
        
        if(x >= n || y >= m)
            return 0;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
            
        int p = solveIt(x + 1, y, n, m);
        int q = solveIt(x, y + 1, n, m);
        
        return dp[x][y] = p + q;
    }
    int uniquePaths(int m, int n) {
        
        memset(dp, -1, sizeof dp);
        return solveIt(0, 0, n, m);
    }
};