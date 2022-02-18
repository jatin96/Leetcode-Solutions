class Solution {
public:
    vector<int> nums;
    int target;
    map<pair<int, int>, int> dp;
    int solveIt(int idx, int currSum) {
        if (idx == nums.size()) {
            if (currSum == target)
                return 1;
            return 0;
        }
        
        if (dp.find({idx, currSum}) != dp.end()) return dp[{idx, currSum}];
        
        int p = solveIt(idx + 1, currSum + nums[idx]);
        int q = solveIt(idx + 1, currSum - nums[idx]);
        
        return dp[{idx, currSum}] = p + q;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        this -> nums = nums;
        this -> target = target;
        return solveIt(0, 0);
    }
};