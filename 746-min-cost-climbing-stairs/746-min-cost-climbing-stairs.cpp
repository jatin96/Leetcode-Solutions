class Solution {
public:
    vector<int> cost;
    int dp[1007];
    int findCost(int idx) {
        if (idx >= cost.size())
            return 0;
        
        if (dp[idx] != -1)
            return dp[idx];
        
        int p = cost[idx] + findCost(idx + 1);
        int q = cost[idx] + findCost(idx + 2);
        
        return dp[idx] = min(p, q);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        this -> cost = cost;
        memset(dp, -1, sizeof dp);
        return min(findCost(0), findCost(1));
    }
};