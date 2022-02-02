class Solution {
public:
    int dp[6000000][2];
    int maxValue, desiredTotal;
    int solveIt(int isPlayerOne, int mask, int currTotal) {
        
        if (dp[mask][isPlayerOne] != -1) return dp[mask][isPlayerOne];
        
        for (int i = 1; i <= maxValue; i++) {
            if ((mask & (1 << i)) == 0) {
                if (currTotal + i >= desiredTotal) {
                    return dp[mask][isPlayerOne] = 1;
                }
                int res = solveIt(isPlayerOne ^ 1, mask | (1 << i), currTotal + i);
                if (res == 0)
                    return dp[mask][isPlayerOne] = 1;
            }
        }
        
        return dp[mask][isPlayerOne] = 0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        memset(dp, -1, sizeof dp);
        this -> maxValue = maxChoosableInteger;
        this -> desiredTotal = desiredTotal;
        
        if (((maxValue * (maxValue + 1)) / 2) < desiredTotal)
            return false;
        
        return solveIt(1, 0, 0) == 1;
    }
};