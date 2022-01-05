class Solution {
public:
    int dp[10007];
    int solveIt(int n) {
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MAX;
        if(dp[n] != -1) return dp[n];
        
        int mini = n;
        for (int i = 1; i * i <= n; i++)
            mini = min(mini, 1 + solveIt(n - i*i));
        
        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof dp);
        return solveIt(n);
    }
};