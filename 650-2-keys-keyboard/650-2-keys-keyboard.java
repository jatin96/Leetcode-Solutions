class Solution {
    final int INF = 99999999;
    int n;
    int[][] dp;
    int solveIt(int screen, int clipboard) {
        if (screen == n)
            return 0;
        
        if (screen > n || clipboard > n)
            return INF;
        
        if (dp[screen][clipboard] != -1) return dp[screen][clipboard];
        
        int p = INF;
        int q = INF;
        
        if (clipboard != screen)
            p = 1 + solveIt(screen , screen);
        
        if (clipboard != 0 && clipboard + screen <= n)
            q = 1 + solveIt(screen + clipboard, clipboard);
        
        return dp[screen][clipboard] = Math.min(p, q);
    }
    public int minSteps(int n) {
        this.n = n;
        dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i ++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        
        
        return solveIt(1, 0);
    }
}