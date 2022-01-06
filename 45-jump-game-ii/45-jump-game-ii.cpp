class Solution {
public:
    vector<int> nums;
    int dp[10007];
    int solveIt(int idx) {
        if (idx >= nums.size() - 1)
            return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int res = 1000000007;
        for (int jump = 1; jump <= nums[idx]; jump++) {
            res = min(res, 1 + solveIt(idx + jump));
        }
        
        return dp[idx] = res;
    }
    int jump(vector<int>& nums) {
        this -> nums = nums;
        memset(dp, -1, sizeof dp);
        return solveIt(0);
    }
};