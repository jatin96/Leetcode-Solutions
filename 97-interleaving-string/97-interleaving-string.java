class Solution {
    String s1, s2, s3;
    int n, m, k;
    int[][] dp;
    private int findInterleaving(int i, int j, int idx) {
        
        if (i == n && j == m && idx == (n + m))
            return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (i < n && s3.charAt(idx) == s1.charAt(i) && findInterleaving(i + 1, j, idx + 1) == 1) return dp[i][j] = 1;
        
        if (j < m && s3.charAt(idx) == s2.charAt(j) && findInterleaving(i, j + 1, idx + 1) == 1) return dp[i][j] = 1;
        
        return dp[i][j] = 0;
        
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
        n = s1.length();
        m = s2.length();
        k = s3.length();
        
        if (n + m != k) return false;
        
        dp = new int[n + 1][m + 1];
        
        for (int i = 0; i < n + 1; i++) 
            for (int j = 0; j < m + 1; j++)
                dp[i][j] = -1;
        
        return findInterleaving(0, 0, 0) == 1 ? true : false;
    }
}