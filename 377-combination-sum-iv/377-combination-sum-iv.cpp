class Solution {
public:
    vector<int> nums;
    int dp[1007];
    int n;
    int solveIt(int currSum) {
        if (currSum == 0)
            return 1;
        
        if (currSum < 0) 
            return 0;
        
        if (dp[currSum] != -1) return dp[currSum];
        int res = 0;
        for (int i = 0; i < n; i++)
            res += solveIt(currSum - nums[i]);
        
        return dp[currSum] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        this -> nums = nums;
        n = nums.size();
        return solveIt(target);
    }
};