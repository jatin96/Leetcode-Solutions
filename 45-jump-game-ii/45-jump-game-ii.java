class Solution {
    int n;
    int[] dp = new int[10004];
    int solve(int idx, int[] nums) {
        if (idx == n - 1)
            return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int maxJump = nums[idx];
        
        int res = 99999999;
        for (int i = 1 ; i <= maxJump; i++) {
            int nextIdx = i + idx;
            if (nextIdx >= n)
                break;
            
            int option =  1 + solve(nextIdx, nums);
            res = Math.min(res, option);    
        }
        
        dp[idx] = res;
        return res;
    }
    public int jump(int[] nums) {
        n = nums.length;
        
        Arrays.fill(dp, -1);
        return solve(0, nums);
    }
}