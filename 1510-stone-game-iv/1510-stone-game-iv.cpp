class Solution {
    
    int dp[100007][3];
    int solveIt(int n, bool isAlice) {
        
        if (dp[n][isAlice] != -1)
            return dp[n][isAlice];
        
        bool flag = false;
        for (int i = 1; i * i <= n; i++) {
            if (n - i*i >= 0 && !solveIt(n - i*i, !isAlice)) {
                flag = true;
                break;
            }
        }
        
        return dp[n][isAlice] = flag;
    }
    public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof dp);
        return solveIt(n, true);
    }
};