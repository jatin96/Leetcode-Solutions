class Solution {
public:
    int maxDays;
    vector<int> jobDifficulty;
    const int INF = 99999999;
    int n;
    int dp[302][15];
    int solveIt(int idx, int daysLeft) {
        
        if (daysLeft == 0 && idx == n)
            return 0;
        
        if (idx == n || daysLeft == 0)
            return INF;
        
        if (dp[idx][daysLeft] != -1) return dp[idx][daysLeft];
        
        int res = INF, dayDifficulty = 0;
        for (int i = idx; i < jobDifficulty.size(); i++) {
            dayDifficulty = max(jobDifficulty[i], dayDifficulty);
            res = min(res, dayDifficulty + solveIt(i + 1, daysLeft - 1));
        }
        
        return dp[idx][daysLeft] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this -> jobDifficulty = jobDifficulty;
        maxDays = d;
        memset(dp, -1, sizeof dp);
        n = jobDifficulty.size();
        
        if (n < d)
            return -1;
        
        return solveIt(0, d);
    }
};