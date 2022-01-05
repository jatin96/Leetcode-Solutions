class Solution {
public:
    int dp[10007];
    int solve_it(vector<int> &nums, int idx, int n) {
        if (idx >= n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        return dp[idx] = max(nums[idx] + solve_it(nums,idx + 2, n), solve_it(nums, idx + 1, n));
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        if (nums.size() == 1)
            return nums[0];
        int p = solve_it(nums, 0, nums.size() - 1);
        memset(dp, -1, sizeof dp);
        int q = solve_it(nums, 1, nums.size());
        return max(p, q);
    }
};