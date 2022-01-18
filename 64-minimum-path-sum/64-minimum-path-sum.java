class Solution {
    int n, m;
    int[][] dp;
    
    int solveIt(int grid[][], int x, int y) {
        if (x >= n || y >= m) return Integer.MAX_VALUE;
        if (x == n - 1 && y == m - 1) return grid[x][y];
        if (dp[x][y] != -1 ) return dp[x][y];
        
        int p = solveIt(grid, x + 1, y);
        int q = solveIt(grid, x, y + 1);
        int res = Math.min(p,q) + grid[x][y];
        dp[x][y] = res;
        return res;
    }
    public int minPathSum(int[][] grid) {
        
        n = grid.length;
        m = grid[0].length;
        dp = new int[n][m];
        
        for (int[] row: dp)
        Arrays.fill(row, -1);
        
        return solveIt(grid, 0 , 0);
    }
}