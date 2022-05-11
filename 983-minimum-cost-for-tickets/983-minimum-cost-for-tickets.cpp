class Solution {
public:
    vector<int> days;
    vector<int> costs;
    vector<int> dp;
    int minCost(int dayIdx) {
        if (dayIdx >= days.size())
            return 0;
        
        if (dp[dayIdx] != -1)
            return dp[dayIdx];
        
        int res = 100000000;
        int pos = lower_bound(days.begin(), days.end(), days[dayIdx] + 1) - days.begin();
        res = min(res, costs[0] + minCost(pos));
        pos = lower_bound(days.begin(), days.end(), days[dayIdx] + 7) - days.begin();
        res = min(res, costs[1] + minCost(pos));
        pos = lower_bound(days.begin(), days.end(), days[dayIdx] + 30) - days.begin();
        res = min(res, costs[2] + minCost(pos));
        return dp[dayIdx] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this -> days = days;
        this -> costs = costs;
        dp.resize(this -> days.size() + 1, -1);
        
        return minCost(0);
    }
};