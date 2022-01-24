class Solution {
public:
    long long dp[100];
    int solveIt(int target, int cnt) {
        if (target == 0) {
            if (cnt > 1)
                return 1;
            
            return -1;
        }
        
        if (target < 0)
            return -1;
        
        if (dp[target] != -1) return dp[target];
        
        int res = -1;
        for (int i = 1; i <= target; i++) {
            int tmp = i * solveIt(target - i, cnt + 1);
            res = max(res, tmp);
        }
        
        return dp[target] = res;
    }
    int integerBreak(int n) {
        
        memset(dp, -1, sizeof dp);
        return solveIt(n, 0);
        
    }
};