class Solution {
public:
    vector<int> prices;
    int n;
    int dp[50007][2];
    int fee;
    int solveIt(int idx, bool isBuy) {
        if (idx == n)
            return 0;
        
        if (dp[idx][isBuy] != -1)
            return dp[idx][isBuy];
        
        int p = 0, q = 0, r = 0;
        
        p = solveIt(idx + 1, isBuy);
        
        if(isBuy)
             q = -1 * prices[idx] + solveIt(idx + 1, !isBuy);
        else
             r = prices[idx] - fee + solveIt(idx + 1, !isBuy);
        
        return dp[idx][isBuy] = max({p, q, r});
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        this -> prices = prices;
        n = prices.size();
        this -> fee = fee;
        memset(dp, -1, sizeof dp);
        return solveIt(0, true);
    }
};