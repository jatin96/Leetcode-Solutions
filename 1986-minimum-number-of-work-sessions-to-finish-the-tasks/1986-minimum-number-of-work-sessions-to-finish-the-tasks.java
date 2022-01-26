class Solution {
    
    int n;
    int[][] dp;
    int[] tasks;
    int sessionTime;
    int solveIt(int mask ,int currSum) {
        if (mask == (1 << n) - 1)
            return 1;
        
        if (dp[mask][currSum] != -1)
            return dp[mask][currSum];
        
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i ++) {
            if ((mask & (1 << i)) == 0) {
                if (currSum + tasks[i] > sessionTime) {
                    res = Math.min(res, 1 + solveIt(mask | (1 << i), tasks[i]));
                } else {
                    res = Math.min(res, solveIt(mask | (1 << i), tasks[i] + currSum));
                }
            }
        }
        
        return dp[mask][currSum] = res;
    }
    public int minSessions(int[] tasks, int sessionTime) {
        n = tasks.length;
        this.tasks = tasks;
        this.sessionTime = sessionTime;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += tasks[i];
        
        dp = new int[1 << n][sum + 2];
        
        for (int i = 0; i < (1<<n); i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = -1;
        
        return solveIt(0, 0);
    }
}