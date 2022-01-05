class Solution {
public:
    int dp[10007];
    int mark[10007];
    int solve_it(int idx, int n) {
        if(idx > n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        
        if(mark[idx] == 0)
            return dp[idx] = solve_it(idx + 1, n);
        
        int p = mark[idx] + solve_it(idx + 2, n);
        int q = solve_it(idx + 1, n);
        
        return dp[idx] = max(p, q);
    }
    int deleteAndEarn(vector<int>& nums) {
        
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mark[nums[i]] += nums[i];
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
        }
                
        
                
        memset(dp, -1, sizeof dp);
        return solve_it(mini, maxi);
    }
};