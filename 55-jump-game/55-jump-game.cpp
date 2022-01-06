class Solution {
public:
    vector<int> nums;
    int dp[10007];
    bool solveIt(int idx) {
        if(idx >= nums.size() - 1)
            return true;
        
        if (dp[idx] != -1) return dp[idx];
        
        for (int jump = 1; jump <= nums[idx]; jump++) {
            bool res = solveIt(idx + jump);
            if(res) return true;
        }
        
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        this -> nums = nums;
        memset(dp, -1, sizeof dp);
        return solveIt(0);
    }
};