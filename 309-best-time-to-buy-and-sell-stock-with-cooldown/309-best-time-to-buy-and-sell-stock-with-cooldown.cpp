class Solution {
public:
    int dp[5007][2];
    vector<int> prices;
    int n;
    int totalProfit(int idx, int isBuy) {
        if (idx >= n)
            return 0;
        
        if(dp[idx][isBuy] != -1)
            return dp[idx][isBuy];
        
        int p = 0, q = 0, r = 0;
        r = totalProfit(idx + 1, isBuy);
        if (isBuy)
            p = -1 * prices[idx] + totalProfit(idx + 1, !isBuy);
        else
            q = prices[idx] + totalProfit(idx + 2, !isBuy);
        
        return dp[idx][isBuy] = max({p, q, r});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        this -> prices = prices;
        n = prices.size();
        return totalProfit(0, true);
        
    }
};