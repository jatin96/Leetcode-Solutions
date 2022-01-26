class Solution {
    
    int [][] dp;
    int n, m, res = 0;
    int[] nums1, nums2;
    private int solveIt(int idx1, int idx2) {
        if (idx1 == n)
            return 0;
        if (idx2 == m)
            return 0;
        
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int res0 = 0;
        if (nums1[idx1] == nums2[idx2])
            res0 = 1 + solveIt(idx1 + 1, idx2 + 1);
        
        int res1 = solveIt(idx1 + 1, idx2);
        int res2 = solveIt(idx1, idx2 + 1);
        
        res = Math.max(Math.max(res1, res2), Math.max(res,res0));
        
        return dp[idx1][idx2] = res0;
    }
    public int findLength(int[] nums1, int[] nums2) {
        n = nums1.length;
        m = nums2.length;
        dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = -1;
       
        this.nums1 = nums1;
        this.nums2 = nums2;
        
        solveIt(0, 0);
        return res;
    }
}