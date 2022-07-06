class Solution {
    int[] dp;
    private int fibonacci(int x) {
        if (x == 0 || x == 1) return x;
        
        if (dp[x] != -1) return dp[x];
        
        return dp[x] = fibonacci(x - 1) + fibonacci(x - 2);
    }
    public int fib(int n) {
        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        
        return fibonacci(n);
    }
}